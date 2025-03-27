#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <iostream>
#include <sstream>

class Reception {
    public:
        Reception();
        ~Reception();

        void start();
    private:
        float _timeMultiplier;
        int _cooksPerKitchen;
        int _restockTime;

        bool processOrder(const std::string &input);
};

#endif // RECEPTION_HPP
