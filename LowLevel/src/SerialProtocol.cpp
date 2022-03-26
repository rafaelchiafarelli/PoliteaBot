#include "SerialProtocol.hpp"
#include "string.h"
#include "stdlib.h"

speed SerialProtocol::CheckData()
{
    speed ret = noMovement;
    if(TransferBuffer())
    {
        //data has the information required
        
        char *begin = strstr(data,"{cmd:");
        char *end = strstr(data,",");

        memset(command,0,10);
        strncpy(command,begin+5,2);
        
        ret = (speed)atoi(command);
        
    }
    else
    {
        ret = transferBufferError;
    }
    return ret;
}

bool SerialProtocol::TransferBuffer()
{
    char *begin = strstr(buffer,"{cmd:");
    char *end = strstr(buffer,"};");
    debug = 0x40;
    if((begin && end) && (begin < end))
    {
        //best case scenario
        debug = 0x80;
        
        strncpy(data,buffer,PROTOCOL_SIZE);
        return true;

    }else if(end>begin)
    {
        //regular case scenario
        if(msg==0)
        {
            char *last = strncpy(begin,data,PROTOCOL_SIZE - (begin-buffer) );
            cur_pos = last-begin; //update the position counter
            msg = 1;
            return false;
        }else if(msg == 1)
        {
            char *last = strncpy(buffer,data+cur_pos,buffer-end);
            cur_pos = last-begin; //update the position counter
            strncpy(end,sec_buffer,PROTOCOL_SIZE-(cur_pos));
            msg = 2;
            return true;  
        }else if(msg >=2)
        {
            char *last = strncpy(sec_buffer,data,PROTOCOL_SIZE);
            cur_pos = last - data;
            strncpy(buffer,data+cur_pos,PROTOCOL_SIZE - cur_pos);
            strncpy(end,sec_buffer,PROTOCOL_SIZE);
            return true;
        }
    }

    return false;
}