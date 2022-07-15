/*
  KeyboardAndMouseControl

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
  - five pushbuttons attached to D2, D3, D4, D5, D6

  The mouse movement is always relative. This sketch reads four pushbuttons, and
  uses them to set the movement of the mouse.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 15 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl
*/

#include "Keyboard.h"
#include "Mouse.h"

// set pin numbers for the five buttons:
const int upButton = 8;
const int downButton = 9;
const int leftButton = 16;
const int rightButton = 10;


void setup() { // initialize the buttons' inputs:
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  

  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
  delay(1000);
  
}

void loop() {
  int btn_count =0;
  // use the pushbuttons to control the keyboard:
  if (digitalRead(upButton) == LOW) {
    while(digitalRead(upButton) == LOW) {
      btn_count+=1;
      delayMicroseconds(1000);
    }
    if(btn_count > 100){
      for(int i=0; i<127; i++)
      {

        Mouse.move(-126+i,-126+i,0);
        delay(2);
      }
      Mouse.move(35,0,0);
      delay(100);
      for(int i=0; i<2; i++)
      {
        Mouse.move(0,125,0);        
        delay(100);
      }
      Mouse.move(17,-15,0);
      Mouse.click();
    }
    btn_count = 0;
  }
  if (digitalRead(downButton) == LOW) {
    while(digitalRead(downButton) == LOW) {
      btn_count+=1;
      delayMicroseconds(1000);
    }
    if(btn_count > 100){
      for(int i=0; i<127; i++)
      {

        Mouse.move(-126+i,-126+i,0);        
        delay(2);
      }
      Mouse.move(35,0,0);
      delay(2);
      for(int i=0; i<2; i++)
      {
        Mouse.move(0,125,0);        
        delay(2);
      }
      Mouse.move(15,27,0);
      Mouse.click();
      
    }
    btn_count = 0;
  
  }
  if (digitalRead(leftButton) == LOW) {
    while(digitalRead(leftButton) == LOW) {
      btn_count+=1;
      delayMicroseconds(1000);
    }
  if(btn_count > 100){
      for(int i=0; i<127; i++)
      {

        Mouse.move(-126+i,-126+i,0);        
        delay(2);
      }
      Mouse.move(0,0,0);
      delay(2);
      for(int i=0; i<2; i++)
      {
        Mouse.move(0,125,0);        
        delay(2);
      }
      Mouse.move(18,55,0);
      Mouse.click();
      
    }
    btn_count = 0;
  
  }
  if (digitalRead(rightButton) == LOW) {
    while(digitalRead(rightButton) == LOW) {
      btn_count+=1;
      delayMicroseconds(1000);
    }
  if(btn_count > 100){
      for(int i=0; i<127; i++)
      {

        Mouse.move(-126+i,-126+i,0);        
        delay(2);
      }
      Mouse.move(0,0,0);
      delay(2);
      for(int i=0; i<2; i++)
      {
        Mouse.move(0,125,0);        
        delay(2);
      }
      Mouse.move(54,55,0);
      Mouse.click();
      
    }
    btn_count = 0; 
  
  }


}
