#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

class Product {
protected:
    int id;
    std::string brand;
    std::string model;
    double price;

public:
    Product(int id, std::string brand, std::string model, double price);
    virtual ~Product() = default;

    virtual void display() const = 0;
    int getId() const;
    double getPrice() const;
};
#endif