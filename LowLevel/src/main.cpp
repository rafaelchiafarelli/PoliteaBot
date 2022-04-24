#include <Arduino.h>
#include "steering.hpp"
#include "SerialProtocol.hpp"
#include "string.h"
//#define PROTOCOL_SIZE 50

Steering st;
SerialProtocol pt;

int LED=13;
void setup() {
      // put your setup code here, to run once:
    for(int i = 0; i<= 13; i++)
    {
      pinMode(i,OUTPUT);

    }
    
    digitalWrite(LED,HIGH);
    st.disable();
    st.stop();
    st.SetSpeed(noMovement);         
    cli();//stop interrupts



    //timer 1 and 2 used as pwd generators for the motors
      TCCR1A = 0xff;
      TCCR1B = 0x09;
      TCNT1  = 0;//initialize counter value to 0
      // set compare match register for 1hz increments
      OCR1A = 0x3ff/2;
      
    //timer 1 and 2 used as pwd generators for the motors
      TCCR3A = 0xff;
      TCCR3B = 0x09;
      TCNT3  = 0;//initialize counter value to 0
      // set compare match register for 1hz increments
      OCR3A = 0x3ff/2;
      

    sei();//allow interrupts
    digitalWrite(LED,LOW);
    Serial.setTimeout(1);
    Serial.begin(38400);
    
    while(Serial.available())
    {
      Serial.read();
    }
}//end setup


int t2count = 0;
CommandInfo cmd;
int counter = 0;
void loop() {
  // put your main code here, to run repeatedly:  
  st.fastHandler();  
  t2count++;
  //check for data available
  //update protocol if data was available
  int c = Serial.available();
  //some data is available
  if(c>PROTOCOL_SIZE)
  {
    pt.buffer[PROTOCOL_SIZE+1] = 0;
    Serial.readBytes(pt.buffer,PROTOCOL_SIZE);
    speed sp = pt.CheckData(cmd);
    Serial.println(pt.buffer);
    if(sp < transferBufferError)
    {
      t2count = 0;
      st.SetSpeed(sp);
    }
    else
    {
      Serial.println("error");
    }

  }

  if(t2count>20000)
  {
    st.stop();
    Serial.println("no_data");
    //if no heartbeat -- stop the machine
    while(Serial.available())
    {
      Serial.read();
    }
    memset(pt.buffer,0,PROTOCOL_SIZE);
    t2count=0;
  }

}

