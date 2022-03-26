#pragma once
#include "hw_definitions.hpp"

class fastPort{
    private:
        unsigned char pins = 0b00000000;
        unsigned char pin_dir = 0b11111111;
        
    public:
        void fastHandler();
        void setPort(int pin, bool st);
        void configPort(int pin, bool dir);
};