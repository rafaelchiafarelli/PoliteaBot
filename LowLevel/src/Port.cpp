#include "Port.hpp"
#include <avr/io.h>
void fastPort::fastHandler()
{
    PORTK = pins;
}


void fastPort::setPort(int pin, bool st)
{
    if(!st)
    {
        switch(pin)
        {
            case 0:
                pins = pins | 0b00000001;
                break;
            case 1:
                pins = pins | 0b00000010;
                break;
            case 2:
                pins = pins | 0b00000100;
                break;
            case 3:
                pins = pins | 0b00001000;
                break;
            case 4:
                pins = pins | 0b00010000;
                break;
            case 5:
                pins = pins | 0b00100000;
                break;
            case 6:
                pins = pins | 0b01000000;
                break;
            case 7:
                pins = pins | 0b10000000;
                break;
            default:
                break;            
        }
    }
    else
    {
        switch(pin)
        {
            case 0:
                pins = pins & 0b11111110;
                break;
            case 1:
                pins = pins & 0b11111101;
                break;
            case 2:
                pins = pins & 0b11111011;
                break;
            case 3:
                pins = pins & 0b11110111;
                break;
            case 4:
                pins = pins & 0b11101111;
                break;
            case 5:
                pins = pins & 0b110111111;
                break;
            case 6:
                pins = pins & 0b101111111;
                break;
            case 7:
                pins = pins & 0b011111111;
                break;
            default:
                break;            
        }
    }    
}

void fastPort::configPort(int pin, bool dir)
{
    if(dir)
    {
        unsigned char direction = (0x00 | dir)<<pin;
        pin_dir = pin_dir | direction;
    }
    else
    {
        unsigned char direction = (0xff & dir)<<pin;
        pin_dir = pin_dir & direction;
    }
    DDRK = pin_dir;
}