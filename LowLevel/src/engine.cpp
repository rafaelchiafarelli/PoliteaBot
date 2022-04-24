#include "engine.hpp"
#include "Arduino.h"
void Engine::UpdateEngine()
{
    
    p->setPort(pin_dir,dir);
    p->setPort(pin_en,(bool)enabled);
    if(time < rot_low[sp])
    {
        p->setPort(pin_step,true);
    }
    else
    {
        p->setPort(pin_step,false);
    }
    time++;
    if(time >= rot_high[sp])
    {
        time=0;
    }
    OCR1A = 0x3ff/2;
    OCR3A = 0x3ff/2;
    switch (sp)
    {
    case 0:
        TCCR1B = 0x0d;
        TCCR3B = 0x0d;
        break;
    case 1:
        TCCR1B = 0x0c;
        TCCR3B = 0x0c;
        break;
    case 2:
        TCCR1B = 0x0b;
        TCCR3B = 0x0b;
        break;
    case 3:
        TCCR1B = 0x0a;
        TCCR3B = 0x0a;
        break;
    case 4:
        TCCR1B = 0x09;
        TCCR3B = 0x09;
        break;
    case 5:
        TCCR1B = 0x00;
        TCCR3B = 0x00;
        break;
     
    default:
        TCCR1B = 0x00;
        TCCR3B = 0x00;
        break;
    }

}

void Engine::Stop()
{
    p->setPort(pin_en,false);
    enabled = turned_off;
    sp = halted;
}

void Engine::Disable()
{
    enabled = turned_off;
}

void Engine::Enable()
{
    enabled = turned_on;
}

void Engine::SetSpeed(rotation_speed _sp)
{
    if(enabled == turned_on)
        sp = _sp;
}
