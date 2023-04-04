#include <Arduino.h>

#include "RB_class_MENU.h"
#include "RB_functions.h"
#include "RB_defines.h"
#include "button_struct.h"
#include "BluetoothSerial_obj.h"
#include "Display_print.h"

MENU_widget RoadBookApp;

// extern unsigned char image[];
// extern Paint paint;    // width should be the multiple of 8 
// extern Epd epd;

// this is a test

void setup() {
    Serial.begin(115200);
    RoadBookApp.AppLoop();
}
 



void loop() {
}

    // is not executed
    // PrintOnDisplay("Hello from Setup");
    // pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
    // attachInterrupt(PIN_BUTTON_LEFT, LX_ButtonISR, FALLING);

    // pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);
    // attachInterrupt(PIN_BUTTON_RIGHT, RX_ButtonISR, FALLING);
    // esp_sleep_enable_ext1_wakeup(BITMASK, ESP_EXT1_WAKEUP_ANY_HIGH);


