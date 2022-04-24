#pragma once
#include "SpeedType.hpp"
#include "string.h"
#define PROTOCOL "{cmd:%d,hb:%llu}"
//example: {cmd:05,y:00,t:00,hb:00000001};
#define PROTOCOL_SIZE 33

typedef struct {
    /* data */
    speed sp;
    int tilt;
    int yaw;
    unsigned long int time;
}CommandInfo;


class SerialProtocol{

    private:
        
        char sec_buffer[PROTOCOL_SIZE+1];
        int cur_pos = 0;
        int last_pos = 0;        
        unsigned long long hertbeat;
        bool TransferBuffer();
    public:
    char data[PROTOCOL_SIZE+1];
        int msg = 0;
        int debug;
        char command[10];
        char buffer[PROTOCOL_SIZE+1];
        speed CheckData(CommandInfo &);
        SerialProtocol()
        {
            memset(data,0,PROTOCOL_SIZE+1);
            memset(buffer,0,PROTOCOL_SIZE+1);
        }
};


