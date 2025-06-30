#ifndef PRODUCT_REPOSITORY_H
#define PRODUCT_REPOSITORY_H


#include <string>   // std::string 클래스 사용
#include <map>      // std::map 컨테이너 사용 (키-값 쌍 저장)
#include <vector>   // std::vector 컨테이너 사용 (동적 배열)
#include "product.h"  // Product 클래스 정의 포함

class ProductFileRepository {


private:
    std::string filename;
    std::map<int, Product> productList;
    
    static std::string trim(const std::string& s);
    static std::vector<std::string> splitCSV(const std::string& line, char delim);


public:
    ProductFileRepository(const std::string& filename);
    
    
    const std::map<int, Product>& getProductList() const { return productList; }
    std::map<int, Product>& getProductList() { return productList; }
    
    void load();
    void save() const;

};





#endif  // PRODUCT_REPOSITORY_H







