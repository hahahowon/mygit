#ifndef PRODUCT_H
#define PRODUCT

#include <string>


class Product {

private:
    int m_stock;
    double m_price;
    std::string m_name;
    std::string m_category;

public:
    Product(int stock, double price, const std::string& name, const std::string& category);
    int getStock() const;
    double getPrice() const;
    const std::string& getName() const;
    const std::string& getCategory() const;

    void setStock(int stock);
    void setPrice(double price);
    void setName(const std::string& name);
    void setCategory(const std::string& category);

    bool operator==(const Product& other) const;
    bool operator!=(const Product& other) const;
};

#endif  // PRODUCT