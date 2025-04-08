#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <string>
#include <vector>
#include <iostream>

class Kitchen {
    public:
        Kitchen(int id, int cooksPerKitchen, int maxCapacity);

        bool canAcceptOrder() const;
        void assignOrder(const std::string &type, const std::string &size);
        int getOrders() const;
        int getId() const;

    private:
        int _id;
        int _cooksPerKitchen;
        int _maxCapacity;
        int _currentOrders;
};


#endif // KITCHEN_HPP