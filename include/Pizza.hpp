#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>

enum class PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum class PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

class Pizza {
    public:
        static bool isSizeValid(const std::string &size);
        static bool isTypeValid(const std::string &type);

    private:
        static const std::unordered_set<std::string> _validSizes;
        static const std::unordered_set<std::string> _validTypes;
};

#endif // PIZZA_HPP