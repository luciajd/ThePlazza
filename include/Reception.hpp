#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include "Pizza.hpp"
#include "Error.hpp"
#include "Kitchen.hpp"

#include <iostream>
#include <sstream>
#include <queue>
#include <string>

struct Order {
    std::string type;
    std::string size;
    int quantity;
};

class Reception {
    public:
        Reception();
        ~Reception();

        void start();
        Order parseOrder(const std::string &order);
        bool processOrder(const std::string &input);
    private:
        std::queue<Order> _orders;
        std::vector<Kitchen> _kitchens;

        void dispatchOrders();
        void createKitchen();
        int _kitchenCounter = 0;
};

#endif // RECEPTION_HPP
