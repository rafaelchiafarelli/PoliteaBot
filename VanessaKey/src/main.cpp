#include "Keyboard.h"
void CheckForKey(int key);
#define KEY_LOW 1000
// set pin numbers for the five buttons:
const int Buttons[] = {8,9,10,16};


int btn_count;

void setup() {
    pinMode(Buttons[0], INPUT_PULLUP);
    pinMode(Buttons[1], INPUT_PULLUP);
    pinMode(Buttons[2], INPUT_PULLUP);
    pinMode(Buttons[3], INPUT_PULLUP);



    
    // initialize control over the keyboard:
    Keyboard.begin();
    btn_count = 0;
}

void loop() {
  // check for incoming serial data:

  // use the pushbuttons to control the keyboard:
  if(btn_count >= 0 && btn_count <= 3)
  {
    CheckForKey(Buttons[btn_count]);
  }
  btn_count += 1;
  if (btn_count > 3)
  {
    btn_count = 0;
  }
  
}

void CheckForKey(int key){
  long int timecount = 0;
  if (digitalRead(key) == LOW) {
    
    while(digitalRead(key) == LOW && timecount < KEY_LOW) {
      timecount+=1;
      delayMicroseconds(100);
    }
    if (digitalRead(key) == LOW && timecount >= KEY_LOW)
    {
    
      switch(key)
      {
        case 8:
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_RIGHT_ARROW);   
        break;
        case 9:
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_DOWN_ARROW);

        break;
        case 10:
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_UP_ARROW);      
        break;
        case 16:
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_ARROW);  
               
        break;
      }
      delay(2);
      Keyboard.releaseAll();      
      
    }
  }
  //hold them here
  while(digitalRead(key) == LOW ) {
    delayMicroseconds(100);
  }
}