#ifndef HEADPHONES_H
#define HEADPHONES_H
#include "Electronics.h"

class Headphones : public Electronics {
public:
    using Electronics::Electronics;
    void display() const override {
        std::cout << "[Headphones] ID: " << id << " | " << brand << " " << model << " | Price: $" << price << "\n";
    }
};
#endif