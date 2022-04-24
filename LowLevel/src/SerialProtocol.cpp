#include "SerialProtocol.hpp"
#include "string.h"
#include "stdlib.h"

speed SerialProtocol::CheckData(CommandInfo &cmd)
{
    speed ret = noMovement;
    if(TransferBuffer())
    {
        //data has the information required
        
        char *begin = strstr(data,"{cmd:")+5;
        char *end = strstr(data,",");

        memset(command,0,10);
        if( !end || !begin)
        {
            return anothererror;
        }
        strncpy(command,begin,end - begin);

        ret = (speed)atoi(command);

        if (ret > transferBufferError)
        {
            return transferBufferError;
        }

        char data[9];
        memset(data,0,9);
        end = strstr(end,",");
        char *tilt = strstr(data,",t:")+3;
        if(tilt)
        {
            strncpy(data,tilt,end-tilt);
            cmd.tilt = atoi(data);
        }

        memset(data,0,9);
        char *yaw = strstr(data,",y:")+3;
        end = strstr(end,",");        
        if(yaw)
        {
            strncpy(data,yaw,end-yaw);
            cmd.yaw = atoi(data);
        }

        memset(data,0,9);
        char *h_b = strstr(data,",hb:")+4;
        end = strstr(end,"}");        
        if(h_b)
        {
            strncpy(data,h_b,end-h_b);
            cmd.time = atoi(data);
        }


    }
    else
    {
        ret = anothererror2;
    }
    return ret;
}

bool SerialProtocol::TransferBuffer()
{
    char *begin = strstr(buffer,"{cmd:");
    char *end = strstr(buffer,"};");
    if((begin && end) && (begin < end))
    {
        strncpy(data,buffer,PROTOCOL_SIZE);
        return true;
    }
    return false;
}