#include "product.h"




Product::Product(int stock, double price, const std::string& name, const std::string& category)
    : m_stock(stock), m_price(price), m_name(name), m_category(category) {}

/*getter functions*/


int Product::getStock() const {return m_stock;}

double Product::getPrice() const {return m_price;}

const std::string& Product::getName() const {return m_name;}

const std::string& Product::getCategory() const {return m_category;}


/*setter functions*/

void Product::setStock(int stock) {m_stock = stock;}

void Product::setPrice(double price) {m_price = price;}

void Product::setName(const std::string& name) {m_name = name;}

void Product::setCategory(const std::string& category) {m_category = category;}

bool Product::operator==(const Product& other) const {
    return m_name == other.m_name;
}

bool Product::operator!=(const Product& other) const {
    return !(*this == other);
}



