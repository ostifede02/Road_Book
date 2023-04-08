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
	static int currentStateCLK;
    static int lastStateCLK = digitalRead(CLK);
    static unsigned long lastButtonPress = 0;


    while(true){
        currentStateCLK = digitalRead(CLK);

        if(currentStateCLK != lastStateCLK){

            if (digitalRead(DT) != currentStateCLK) {
                lastStateCLK = currentStateCLK;
                delay(200);
                return 'l';
            } else {
                // Encoder is rotating CW so increment
                lastStateCLK = currentStateCLK;
                delay(200);
                return 'r';
            }

            // Remember last CLK state
        }
        

        lastButtonPress = millis();
        while(digitalRead(SW) == LOW){
            delay(100);
            if(digitalRead(SW) == HIGH){
                if (millis() - lastButtonPress > 600) {
                    return 'L';
                }
                else {
                    return 'R';
                }
            }
        }
    }
}














// char GetInterruptCommand(void){
//     static BluetoothSerial SerialBT;
//     static bool isConnected = false;
//     char cmd;
    
//     if(!isConnected){
//         SerialBT.begin("ESP32");            // Bluetooth device name
//         isConnected = true;
//     }

//     while (!SerialBT.available()){}     // simulate sleepmode
//     cmd = SerialBT.readString()[0];
//     return cmd;
// }

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