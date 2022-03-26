#include "engine.hpp"

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
