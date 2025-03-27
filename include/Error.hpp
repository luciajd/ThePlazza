#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>
#include <string>
#include <iostream>

class Error : public std::runtime_error {
    public:
        explicit Error(const std::string &message)
            : std::runtime_error("\033[1;31m" + message + "\033[0m") {}
};

class ErrorHandling {
    public:
        void validateOrder(const std::string &type, const std::string &size, const std::string &quantityStr);
        void help(void);
        void orderHelp(void);
};

#endif // ERROR_HPP