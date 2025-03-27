#include "Pizza.hpp"

const std::unordered_set<std::string> Pizza::_validSizes = {
    "S", "M", "L", "XL", "XXL"
};

const std::unordered_set<std::string> Pizza::_validTypes = {
    "regina", "margarita", "americana", "fantasia"
};

bool Pizza::isSizeValid(const std::string &size)
{
    return _validSizes.find(size) != _validSizes.end();
}

bool Pizza::isTypeValid(const std::string &type)
{
    return _validTypes.find(type) != _validTypes.end();
}
