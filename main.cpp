#include <iostream>
#include <string>
#include "Inventory.h"
#include "Smartphone.h"
#include "Laptop.h"
#include "Headphones.h"
#include "Smartwatch.h"

int main() {
    Inventory<Product> store;
    int choice;

    while (true) {
        std::cout << "\n--- TECH CITY MANAGEMENT SYSTEM ---\n";
        std::cout << "1. Add New Item\n2. Delete Item\n3. Show Inventory\n4. Exit\nChoice: ";
        std::cin >> choice;

        try {
            if (choice == 1) {
                std::string type, brand, model;
                int id;
                double price;

                std::cout << "Type (Smartphone, Laptop, Headphones, Smartwatch): ";
                std::cin >> type;
                std::cout << "ID: "; std::cin >> id;
                std::cout << "Brand: "; std::cin >> brand;
                std::cin.ignore();
                std::cout << "Model: "; std::getline(std::cin, model);
                std::cout << "Price: "; std::cin >> price;

                if (type == "Smartphone" || type == "smartphone")
                    store.addItem(std::make_shared<Smartphone>(id, brand, model, price));
                else if (type == "Laptop" || type == "laptop")
                    store.addItem(std::make_shared<Laptop>(id, brand, model, price));
                else if (type == "Headphones" || type == "headphones")
                    store.addItem(std::make_shared<Headphones>(id, brand, model, price));
                else if (type == "Smartwatch" || type == "smartwatch")
                    store.addItem(std::make_shared<Smartwatch>(id, brand, model, price));
                else
                    throw InventoryException("Tech City doesn't support the gadget type: " + type);

                std::cout << "Item added to inventory.\n";

            }
            else if (choice == 2) {
                int id;
                std::cout << "Enter ID to delete: "; std::cin >> id;
                store.deleteItem(id);
                std::cout << "Item removed.\n";

            }
            else if (choice == 3) {
                std::cout << "\n--- Current Tech City Inventory (Sorted by Price) ---\n";
                store.listAll();

            }
            else if (choice == 4) break;

        }
        catch (const InventoryException& e) {
            std::cerr << "STORE ERROR: " << e.what() << "\n";
        }
    }
    return 0;
}