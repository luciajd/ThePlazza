#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include "Pizza.hpp"
#include "Error.hpp"

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
    private:
        float _timeMultiplier;
        int _cooksPerKitchen;
        int _restockTime;
        std::queue<Order> _orders;
        
        Order parseOrder(const std::string &order);
        bool processOrder(const std::string &input);
        
};

#endif // RECEPTION_HPP
