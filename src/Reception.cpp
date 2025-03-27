#include "Reception.hpp"

Reception::Reception() {}

Reception::~Reception() {}

void Reception::start()
{
    std::string input;

    while (true) {
        std::cout << "Enter your order (or type 'exit' to quit): " << std::endl;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        if (!processOrder(input)) {
            std::cout << "Invalid order. Please try again." << std::endl;
        }
    }
}

bool Reception::processOrder(const std::string &input)
{
    std::istringstream stream(input);
    std::string order;

    while (std::getline(stream, order, ';')) {
        std::cout << "Processing order: " << order << std::endl;
    }

    return true;
}
