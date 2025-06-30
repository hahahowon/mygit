#ifndef PRODUCT_MANAGEMENT_H
#define PRODUCT_MANAGEMENT_H

#include "productRepository.h"
#include <memory>

class ProductManagement{
private:
    std::unique_ptr<ProductFileRepository> repository;

public:
    ProductManagement(const std::string& filename);

    //CRUD                          

    int addProduct(const std::string& name, double price, int stock, const std::string& category);
    bool updateProduct(int product_num, const std::string& name, double price, int stock, const std::string& category);
    bool deleteProduct(int product_num);

    std::vector<std::pair<int, Product>> getAllProducts() const;
    std::pair<int, Product>* findProductByName(const std::string& name) const;  

    void save();

};



#endif // PRODUCT_MANAGEMENT_H







