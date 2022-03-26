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
    pinMode(LED,OUTPUT);
    digitalWrite(LED,HIGH);
    st.disable();
    st.stop();
    st.SetSpeed(noMovement);         
    cli();//stop interrupts

    //set timer0 interrupt at 2kHz
      TCCR0A = 0;// set entire TCCR0A register to 0
      TCCR0B = 0;// same for TCCR0B
      TCNT0  = 0;//initialize counter value to 0
      // set compare match register for 2khz increments
      OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
      // turn on CTC mode
      TCCR0A |= (1 << WGM01);
      // Set CS01 and CS00 bits for 64 prescaler
      TCCR0B |= (1 << CS01) | (1 << CS00);   
      // enable timer compare interrupt
      TIMSK0 |= (1 << OCIE0A);

    //set timer1 interrupt at 10Hz
      TCCR1A = 0;// set entire TCCR1A register to 0
      TCCR1B = 0;// same for TCCR1B
      TCNT1  = 0;//initialize counter value to 0
      // set compare match register for 1hz increments
      OCR1A = 1562;// = (16*10^6) / (10*1024) - 1 (must be <65536)
      // turn on CTC mode
      TCCR1B |= (1 << WGM12);
      // Set CS10 and CS12 bits for 1024 prescaler
      TCCR1B |= (1 << CS12) | (1 << CS10);  
      // enable timer compare interrupt
      TIMSK1 |= (1 << OCIE1A);

    sei();//allow interrupts
    digitalWrite(LED,LOW);
    Serial.setTimeout(1);
    Serial.begin(9600);
    

}//end setup
int counter = 0;
void loop() {
  // put your main code here, to run repeatedly:  
}

//int t1count = 0;
ISR(TIMER0_COMPA_vect){  //change the 0 to 1 for timer1 and 2 for timer2
  //timer0
  //t1count++;
  st.fastHandler();  
  /*
  if (t1count >= 1)
  {
    
    if(t1count>=2)
    {
      digitalWrite(LED,LOW);
      
      t1count=0;
    }
  }
  */
}

int t2count = 0;

ISR(TIMER1_COMPA_vect){  //change the 0 to 1 for timer1 and 2 for timer2
  t2count++;
  //check for data available
  //update protocol if data was available
  int c = Serial.available();
  //some data is available
  if(c>=PROTOCOL_SIZE)
  {
    Serial.readBytes(pt.buffer,PROTOCOL_SIZE);
    Serial.println("data");
    speed sp = pt.CheckData();
    t2count = 0;
    st.SetSpeed(sp);
  }

  if (t2count > 10)
  {
    if(t2count>20)
    {
      Serial.println("data");
      //if no heartbeat -- stop the machine
      memset(pt.buffer,0,PROTOCOL_SIZE);
      while(Serial.available())
      {
        Serial.read();
      }
      st.stop();
      t2count=0;
    }
  }
}