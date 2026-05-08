#ifndef SMARTWATCH_H
#define SMARTWATCH_H
#include "Electronics.h"

class Smartwatch : public Electronics {
public:
    using Electronics::Electronics;
    void display() const override {
        std::cout << "[Smartwatch] ID: " << id << " | " << brand << " " << model << " | Price: $" << price << "\n";
    }
};
#endif