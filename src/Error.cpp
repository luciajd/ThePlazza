#include "Error.hpp"
#include "Pizza.hpp"

void ErrorHandling::help(void)
{
    std::cout << "USAGE: ./plazza <multiplier> <cooks> <time>" << std::endl;
    std::cout << "\tmultiplier: for the cooking time of the pizzas." << std::endl;
    std::cout << "\tcooks: number of cooks per kitchen." << std::endl;
    std::cout << "\ttime: time in milliseconds, used by the kitchen stock to replace ingredients." << std::endl;
}

void ErrorHandling::orderHelp(void)
{
    std::cout << "USAGE: <type> <size> x<quantity> ; <type> <size> x<quantity> ; ..." << std::endl;
}


void ErrorHandling::validateOrder(const std::string &type, const std::string &size, const std::string &quantityStr)
{
    if (type.empty() || !Pizza::isTypeValid(type)) {
        throw Error("Missing or invalid pizza type");
        orderHelp();
    }

    if (size.empty() || !Pizza::isSizeValid(size)) {
        throw Error("Missing or invalid pizza size");
        orderHelp();
    }

    if (quantityStr.empty() || quantityStr[0] != 'x') {
        throw Error("Missing or invalid quantity format");
        orderHelp();
    }

    int quantity = std::stoi(quantityStr.substr(1));
    if (quantity <= 0) {
        throw Error("Quantity must be greater than 0");
        orderHelp();
    }
}
