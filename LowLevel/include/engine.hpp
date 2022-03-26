#pragma once
#include"hw_definitions.hpp"
#include "Port.hpp"

typedef enum{
    cw,
    ccw
}direction;

typedef enum
{
    turned_on,
    turned_off
}cur_state;

typedef enum{
    UltraSlow,
    Slow,
    Medium,
    Fast,
    UltraFast,
    halted,
    rotation_max
}rotation_speed;


class Engine{
    private:
        int time=0;
        fastPort *p = nullptr;
        direction dir;
        cur_state enabled;
        rotation_speed sp;
        int rot_high[rotation_max] = ROTATION_SPEED_HIGH;
        int rot_low[rotation_max] = ROTATION_SPEED_LOW;
        int total_time = 0;        
        int pin_en = 0;
        int pin_dir = 0;
        int pin_step = 0;

    public:
        void SetDirection(direction cc)
        {
            dir = cc;
        };

        void UpdateEngine();
        void Stop();
        void Disable();
        void Enable();
        void SetSpeed(rotation_speed sp);
        Engine() = delete;
        Engine(int en_pin, int dir_pin, int step_pin, fastPort *ext_p)
        {
            pin_en = en_pin;
            pin_dir = dir_pin;
            pin_step = step_pin;
            p = ext_p;
            p->configPort(pin_en,true);
            p->configPort(pin_dir,true);
            p->configPort(pin_step,true);
        };
        ~Engine() = default;
};