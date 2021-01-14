/* Esp32 bluetooth programmable keyboard for bCNC
   by: George Kokolakis, SV3QUP , kokolakis@gmail.compare
   date: January 10, 2021
   This code turns an esp32 to a custom bluetooth keybard. The keyboard is programmed as a jogging pendant and control panel for the bCNC (https://github.com/vlachoudis/bCNC) and OKKCNC (https://github.com/onekk/OKKCNC) GRBL CNC Command senders. It uses 20 button matrix keyboard from ebay and an external push button so you can use each button twice if needed.
   
   This code is based on the Ble keyboard library of T-vk (https://github.com/T-vK/ESP32-BLE-Keyboard) and the keypad library by Mark Stanley and Alexander Brevig (https://playground.arduino.cc/Code/Keypad/). 
   
   The idea to make this code was from the great work of witnessmenow found on this instractables tutorial: https://www.instructables.com/DIY-Bluetooth-Macro-Keypad/
   
#include <BleKeyboard.h>
#include "Keypad.h"
int S = 33; //pin to connect shift push button
const byte ROWS = 5; //five rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'a','b','c','d'},
  {'f','g','h','+'},
  {'p','q','r','-'},
  {'*','2','/','9'},
  {'6','8','4','3'}
};


//These are the pins on esp32 that the matrix keyboard is connected
//rows and columns respectively
byte rowPins[ROWS] = {22, 19, 23, 18,5}; 
byte colPins[COLS] = {17, 16, 4, 32}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
BleKeyboard bleKeyboard("bCNC_Pegant", "SV3QUP", 100);
//Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;

void setup() {
  Serial.begin(9600);
  bleKeyboard.begin();
  pinMode (S, INPUT_PULLUP);

}


void loop() {
  char key = keypad.getKey();
  int shift = digitalRead(S);
    if (bleKeyboard.isConnected() && key) {
    Serial.println(key);
    if (shift == 1) {
    switch (key) {
      case '2':
        bleKeyboard.press(232);
        break;
      case '3'://9
        bleKeyboard.press(227);
        break;
      case '4':
        bleKeyboard.press(230);
        break;
      case '6':
        bleKeyboard.press(228);
        break;
      case '8':
        bleKeyboard.press(226);
        break;
      case '9':
        bleKeyboard.press(233);
        break;
      case '+':
        bleKeyboard.press(223);
        break;
      case '-':
        bleKeyboard.press(222);
        break;
      case '*':
        bleKeyboard.press(220);
        break;
      case '/':
        bleKeyboard.press(221);
        break;
       case 'a':
        bleKeyboard.press(KEY_F7);
        break;  
      case 'b':
        bleKeyboard.press(KEY_F8);
        break;  
      case 'c':
        bleKeyboard.press(KEY_F9);
        break;
      case 'd':
        bleKeyboard.press(KEY_F10);
        break;
       case 'g':
        bleKeyboard.press(KEY_F4);
        break;
       case 'h':
        bleKeyboard.press(KEY_F5);
        break;
       case 'p':
        bleKeyboard.press(KEY_F1);
        break;
        case 'q':
        bleKeyboard.press(KEY_F2);
        break;
        case 'f':
        bleKeyboard.press(KEY_F11);
        break; 
           }
//When we press the alternative function push button            
    } else {
            switch (key) {
      case '2':
        bleKeyboard.press(KEY_UP_ARROW);
        break;
      case '3'://9
        bleKeyboard.press(KEY_RIGHT_SHIFT);
        bleKeyboard.press(KEY_F6 );
        break;
      case '4':
        bleKeyboard.press(KEY_RIGHT_ARROW);
        break;
      case '6':
        bleKeyboard.press(KEY_LEFT_ARROW);
        break;
      case '8':
        bleKeyboard.press(KEY_DOWN_ARROW);
        break;
      case '9':
        bleKeyboard.press(KEY_RIGHT_SHIFT);
        bleKeyboard.press(KEY_F5);
        break;
      case '+':
        bleKeyboard.press(KEY_RIGHT_SHIFT);
        bleKeyboard.press(KEY_F1);
        break;
      case '-':
        bleKeyboard.press(KEY_RIGHT_SHIFT);
        bleKeyboard.press(KEY_F2);
        break;
      case '*':
        bleKeyboard.press(220);
        break;
      case '/':
        bleKeyboard.press(221);
        break;
       case 'a':
        bleKeyboard.press(KEY_ESC);
        break;  
      case 'b':
        bleKeyboard.press(KEY_F8);
        break;  
      case 'c':
        bleKeyboard.press(KEY_F9);
        break;
      case 'd':
        bleKeyboard.press(KEY_RETURN);
        break;
       case 'g':
        bleKeyboard.press(KEY_F4);
        break;
       case 'h':
        bleKeyboard.press(KEY_F5);
        break;
       case 'p':
        bleKeyboard.press(KEY_RIGHT_SHIFT);
        bleKeyboard.press(KEY_F3);
        break;
        case 'q':
        bleKeyboard.press(KEY_RIGHT_SHIFT);
        bleKeyboard.press(KEY_F4);
        break;
        case 'r':
        bleKeyboard.press(KEY_F3);
        break;
       case 'f':
        bleKeyboard.press(KEY_F11);
        break; 
           }
    }
    delay(100);
    bleKeyboard.releaseAll(); // this releases the buttons
  }
}
