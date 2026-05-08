#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include "Product.h"

// Level 1 of inheritance
class Electronics : public Product {
public:
    using Product::Product;
    virtual void display() const override = 0;
};
#endif