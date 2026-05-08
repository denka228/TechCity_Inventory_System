#ifndef LAPTOP_H
#define LAPTOP_H
#include "Electronics.h"

class Laptop : public Electronics {
public:
    using Electronics::Electronics;
    void display() const override {
        std::cout << "[Laptop] ID: " << id << " | " << brand << " " << model << " | Price: $" << price << "\n";
    }
};
#endif