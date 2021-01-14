This code turns an esp32 to a custom bluetooth keybard. The keyboard is programmed as a jogging pendant and control panel for the bCNC (https://github.com/vlachoudis/bCNC) and OKKCNC (https://github.com/onekk/OKKCNC) GRBL CNC Command senders. It uses 20 button matrix keyboard from ebay and an external push button so you can use each button twice if needed.
   
   This code is based on the Ble keyboard library of T-vk (https://github.com/T-vK/ESP32-BLE-Keyboard) and the keypad library by Mark Stanley and Alexander Brevig (https://playground.arduino.cc/Code/Keypad/). 
   
   The idea to make this code was from the great work of witnessmenow found on this instractables tutorial: https://www.instructables.com/DIY-Bluetooth-Macro-Keypad.
   The keypad.png file is a simple drawing i created and glued over the matrix keypad in order to have a "real" custom keyboard and to avoid having to remember what every key        does. You can see my version of the keypad in the assembled_keypad.jpg file.
   In order for the custom functios to work, you have to programm your bCNC or OKKCNC shortcuts accordingly. My shortcuts are as follows:
   F1:G10L20P1X0Y0
   
   F2:G10L20P1Z0
   
   F3:G38.2 Z-40 F50
      G10 L20 P0 Z4.8
      G91 G0 Z5
   
   F4:G90G0X0Y0
   
   F5:G90
      G0 X[xmin] Y[ymin]
      G0 X[xmax]
      G0 Y[ymax]
      G0 X[xmin]
      G0 Y[ymin]
   
   F6:ISO3
   
   F7:stop
   
   F8:pause
   
   F9:run
   
   F10:home
   
   F11:G90G0Z[safe]
   
   F12:
   
   Shift+F1:sendhex 91
   
   Shift+F2:sendhex 92
   
   Shift+F3:G53
   G28
   G54
   
   Shift+F4:g53
   G30
   G54
   
   Shift+F5:sendhex 93
   
   Shift+F6:sendhex 94
   
