#include "Product.h"

Product::Product(int id, std::string brand, std::string model, double price)
    : id(id), brand(brand), model(model), price(price) {
}

int Product::getId() const { return id; }
double Product::getPrice() const { return price; }