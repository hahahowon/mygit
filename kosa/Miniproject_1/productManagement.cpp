#include "productManagement.h"
using namespace std;

// 생성자: 파일명을 받아서 ProductFileRepository 객체 생성
ProductManagement::ProductManagement(const string& filename){
    repository = make_unique<ProductFileRepository>(filename);
}

// 상품 추가 (새로운 상품 번호 자동 생성)
int ProductManagement::addProduct(const string& name, double price, int stock, const string& category){
    int product_num = 1;

    // 기존 상품이 있으면 마지막 상품 번호 + 1로 설정
    if(!repository->getProductList().empty()){
        product_num = repository->getProductList().rbegin()->first + 1;
    }
    // 상품 리스트에 새 상품 추가
    repository->getProductList().insert(make_pair(product_num, Product(stock, price, name, category)));
    return product_num;
}   

// 상품 정보 수정 (상품 번호로 찾아서 정보 변경)
bool ProductManagement::updateProduct(int product_num, const string& name, double price, int stock, const string& category){
    auto& productList = repository->getProductList();
    auto it = productList.find(product_num);

    if(it != productList.end()){
        it->second.setName(name);
        it->second.setPrice(price);
        it->second.setStock(stock);
        it->second.setCategory(category);
        return true;
    }
    return false;
}

// 상품 삭제 (상품 번호로 삭제)
bool ProductManagement::deleteProduct(int product_num){
    auto& productList = repository->getProductList();
    return productList.erase(product_num) > 0;
}

// 전체 상품 목록 반환
vector<pair<int, Product>> ProductManagement::getAllProducts() const{

    vector<pair<int, Product>> products;

    // 모든 상품을 벡터에 복사
    for(const auto& pair : repository->getProductList()){
        products.push_back(pair);
    }
    return products;

}

// 상품 이름으로 상품 검색 (최초 1개 반환)
std::pair<int, Product>* ProductManagement::findProductByName(const string& name) const{
    for(const auto& pair : repository->getProductList()){
        if(pair.second.getName() == name){
            return new std::pair<int, Product>(pair);
        }
    }
    return nullptr;
}

// 상품 정보 저장 (CSV 파일 등으로 저장)
void ProductManagement::save(){
    repository->save();
}


