#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "Electronics.h"

class Smartphone : public Electronics {
public:
    using Electronics::Electronics;
    void display() const override {
        std::cout << "[Smartphone] ID: " << id << " | " << brand << " " << model << " | Price: $" << price << "\n";
    }
};
#endif