#include "RB_functions.h"

/*
In this function we have to detect wich button has been pressed and if
it was a short or long press.

The function has to return the following commands:
    'r'     ->      short pressed right button
    'l'     ->      short pressed left button
    'R'     ->      long pressed right button
    'L'     ->      long pressed left button
*/
char GetInterruptCommand(void){
    static BluetoothSerial SerialBT;
    static bool isConnected = false;
    char cmd;
    
    if(!isConnected){
        SerialBT.begin("ESP32");            // Bluetooth device name
        isConnected = true;
    }

    while (!SerialBT.available()){}     // simulate sleepmode
    cmd = SerialBT.readString()[0];
    return cmd;
}

// char GetInterruptCommand(void){
//     char cmd;

//     esp_light_sleep_start();
    
//     return cmd;
// }

// void LX_ButtonISR(void){
//     long int ISR_time_start = millis();
//     int time_swap = 0;

//     while(digitalRead(PIN_BUTTON_LEFT) == HIGH){}

//     time_swap = millis() - ISR_time_start;
// }