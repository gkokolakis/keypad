This code turns an esp32 to a custom bluetooth keybard. The keyboard is programmed as a jogging pendant and control panel for the bCNC (https://github.com/vlachoudis/bCNC) and OKKCNC (https://github.com/onekk/OKKCNC) GRBL CNC Command senders. It uses 20 button matrix keyboard from ebay and an external push button so you can use each button twice if needed.
   
   This code is based on the Ble keyboard library of T-vk (https://github.com/T-vK/ESP32-BLE-Keyboard) and the keypad library by Mark Stanley and Alexander Brevig (https://playground.arduino.cc/Code/Keypad/). 
   
   The idea to make this code was from the great work of witnessmenow found on this instractables tutorial: https://www.instructables.com/DIY-Bluetooth-Macro-Keypad.
   The keypad.png file is a simple drawing i created and glued over the matrix keypad in order to have a "real" custom keyboard and to avoid having to remember what every key        does. 
