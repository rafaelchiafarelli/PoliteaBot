#include "steering.hpp"

void Steering::SetSpeed(speed sp)
{
    if(Movement != sp)
    {
        Movement = sp;
        RigthEngine.Enable();
        LeftEngine.Enable();
        switch (Movement)
        {
        case fwUltraFast:
            LeftEngine.SetSpeed(UltraFast);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(ccw);
            break;

        case fwFast:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(ccw);
            break;
        
        case fwMedium:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(ccw);
            break;

        case fwSlow:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(ccw);
            break;

        case fwUltraSlow:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwfwUltraSlow:
            LeftEngine.SetSpeed(halted);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwfwSlow:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(ccw);
            break;
        
        case ccwfwMedium:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwfwFast:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwfwUltraFast:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(ccw);
            break;

        case cwfwUltraSlow:
            LeftEngine.SetSpeed(halted);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(cw);
            break;

        case cwfwSlow:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(cw);
            break;
        
        case cwfwMedium:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(cw);
            break;

        case cwfwFast:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(cw);
            break;

        case cwfwUltraFast:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(cw);
            break;

        case ccwbkUltraSlow:
            LeftEngine.SetSpeed(halted);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwbkSlow:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(ccw);
            break;
        
        case ccwbkMedium:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwbkFast:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwbkUltraFast:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(ccw);
            break;

        case cwbkUltraSlow:
            LeftEngine.SetSpeed(halted);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(ccw);
            break;

        case cwbkSlow:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(ccw);
            break;
        
        case cwbkMedium:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(ccw);
            break;

        case cwbkFast:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(ccw);
            break;

        case cwbkUltraFast:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(ccw);
            break;


        case ccwUltraSlowSpin:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwSlowSpin:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(ccw);
            break;
        
        case ccwMediumSpin:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwFastSpin:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(ccw);
            break;

        case ccwUltraFastSpin:
            LeftEngine.SetSpeed(UltraFast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(ccw);
            break;

        case cwUltraSlowSpin:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(cw);
            break;

        case cwSlowSpin:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(cw);
            break;
        
        case cwMediumSpin:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(cw);
            break;

        case cwFastSpin:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(cw);
            break;

        case cwUltraFastSpin:
            LeftEngine.SetSpeed(UltraFast);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(cw);
            break;

        case bkUltraFast:
            LeftEngine.SetSpeed(UltraFast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraFast);
            RigthEngine.SetDirection(cw);   
            break;

        case bkFast:
            LeftEngine.SetSpeed(Fast);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Fast);
            RigthEngine.SetDirection(cw);
            break;
        
        case bkMedium:
            LeftEngine.SetSpeed(Medium);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Medium);
            RigthEngine.SetDirection(cw);
            break;

        case bkSlow:
            LeftEngine.SetSpeed(Slow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(Slow);
            RigthEngine.SetDirection(cw);
            break;
            
        case bkUltraSlow:
            LeftEngine.SetSpeed(UltraSlow);
            LeftEngine.SetDirection(ccw);
            RigthEngine.SetSpeed(UltraSlow);
            RigthEngine.SetDirection(cw);
            break;

        default:
            LeftEngine.SetSpeed(halted);
            LeftEngine.SetDirection(cw);
            RigthEngine.SetSpeed(halted);
            RigthEngine.SetDirection(ccw);    
            break;
        }

    }
 
}


void Steering::fastHandler(){

    //calculate the next
    RigthEngine.UpdateEngine();
    LeftEngine.UpdateEngine();
    
    
    //update the output state
    port.fastHandler();    
}



