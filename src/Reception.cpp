#include "Reception.hpp"

Reception::Reception() {}

Reception::~Reception() {}

void Reception::start()
{
    std::string input;

    while (input != "exit") {
        std::cout << "\033[1;35mEnter your order (or type 'exit' to quit):\033[0m" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        if (!processOrder(input)) {
            std::cout << "\033[1;31m" << "Invalid order. Please try again." << "\033[0m" << std::endl;
        }
    }
}

Order Reception::parseOrder(const std::string &order)
{
    ErrorHandling error;
    std::istringstream stream(order);   
    std::string type;
    std::string size;
    std::string quantityStr;

    
    stream >> type >> size >> quantityStr;
    
    error.validateOrder(type, size, quantityStr);
    
    int quantity = std::stoi(quantityStr.substr(1));
    return { type, size, quantity };
}

bool Reception::processOrder(const std::string &input)
{
    std::istringstream stream(input);
    std::string orderStr;

    while (std::getline(stream, orderStr, ';')) {
        try {
            Order order = parseOrder(orderStr);
            _orders.push(order);
            dispatchOrders();
        } catch (const Error &e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }

    return true;
}

void Reception::dispatchOrders()
{
    while (!_orders.empty()) {
        Order order = _orders.front();
        _orders.pop();

        int pizzaRemaining = order.quantity;

        bool kitchenAvailable = false;
        for (auto &kitchen : _kitchens) {
            if (kitchen.canAcceptOrder()) {
                kitchenAvailable = true;
                break;
            }
        }
        if (!kitchenAvailable) {
            createKitchen();
        }

        std::cout << "\033[1;32mOrder received:\033[0m "
                  << "Pizza: " << order.type
                  << ", size: " << order.size
                  << ", quantity: " << order.quantity
                  << std::endl;

        while (pizzaRemaining > 0) {
            bool assigned = false;
            for (auto &kitchen : _kitchens) {
                if (kitchen.canAcceptOrder()) {
                    kitchen.assignOrder(order.type, order.size);
                    pizzaRemaining--;
                    assigned = true;
                    break;
                }
            }

            if (!assigned) {
                createKitchen();
            }
        }
    }
}



void Reception::createKitchen()
{
    int cooksPerKitchen = 5;
    int maxPizzas = cooksPerKitchen * 2;

    Kitchen newKitchen(_kitchenCounter++, cooksPerKitchen, maxPizzas);
    _kitchens.push_back(std::move(newKitchen));
    std::cout << "\033[1;34mNew kitchen created with ID: " << newKitchen.getId() << "\033[0m" << std::endl;
}