#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <string>

class InventoryException : public std::runtime_error {
public:
    InventoryException(const std::string& msg) : std::runtime_error(msg) {}
};

template <typename T>
class Inventory {
private:
    std::vector<std::shared_ptr<T>> items;

public:
    void addItem(std::shared_ptr<T> item) { items.push_back(item); }

    void deleteItem(int id) {
        auto originalSize = items.size();
        items.erase(std::remove_if(items.begin(), items.end(),
            [id](const std::shared_ptr<T>& item) { return item->getId() == id; }),
            items.end());

        if (items.size() == originalSize) {
            throw InventoryException("Error: ID " + std::to_string(id) + " not found in warehouses.");
        }
    }

    void listAll() {
        std::sort(items.begin(), items.end(),
            [](const std::shared_ptr<T>& a, const std::shared_ptr<T>& b) {
                return a->getPrice() < b->getPrice();
            });
        for (const auto& item : items) item->display();
    }
};
#endif