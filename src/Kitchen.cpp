#include "Kitchen.hpp"

Kitchen::Kitchen(int id, int cooksPerKitchen, int maxCapacity)
    : _id(id), _cooksPerKitchen(cooksPerKitchen), _maxCapacity(maxCapacity), _currentOrders(0) {}

bool Kitchen::canAcceptOrder() const
{
    return _currentOrders < _maxCapacity;
}

void Kitchen::assignOrder(const std::string &type, const std::string &size)
{
    if (canAcceptOrder()) {
        _currentOrders++;
        std::cout << "Kitchen " << _id << " is preparing a " << size << " " << type << " pizza." << std::endl;
    } else {
        std::cout << "Kitchen " << _id << " cannot accept more orders." << std::endl;
    }
}

int Kitchen::getOrders() const
{
    return _currentOrders;
}

int Kitchen::getId() const
{
    return _id;
}
