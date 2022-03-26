#pragma once

#include "Port.hpp"
#include "engine.hpp"
#include "SpeedType.hpp"

class Steering
{
    private:
        fastPort port;
        Engine LeftEngine;
        Engine RigthEngine;
        
        speed Movement = noMovement;       
    public:
        void SetSpeed(speed sp);
        
        void stop()
        {
            Movement =noMovement;
        
            LeftEngine.Stop();
            RigthEngine.Stop();    
        };
        void disable()
        {
            LeftEngine.Disable();
            RigthEngine.Disable(); 
        };
        void fastHandler();
        Steering():
            RigthEngine(MOTOR_RIGHT_EN,MOTOR_RIGHT_DIR,MOTOR_RIGHT_STEP,&port),
            LeftEngine(MOTOR_LEFT_EN,MOTOR_LEFT_DIR,MOTOR_LEFT_STEP,&port)
        {

        };
        ~Steering() = default;
};