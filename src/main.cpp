#include <Arduino.h>

#include "RB_class_MENU.h"
#include "RB_functions.h"
#include "RB_defines.h"
#include "button_struct.h"
#include "BluetoothSerial_obj.h"
// #include "Display_print.h"
#include "Display_print_Adafruit_lib.h"

MENU_widget RoadBookApp;
extern GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display;
extern U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;


void setup() {
    Serial.begin(115200);

    display.init();
    display.setTextColor(GxEPD_BLACK);
    display.firstPage();
    display.setRotation(1);

    u8g2Fonts.begin(display); // connect u8g2 procedures to Adafruit GFX
    delay(1000);
    u8g2Fonts.setForegroundColor(GxEPD_BLACK);         // apply Adafruit GFX color
    u8g2Fonts.setBackgroundColor(GxEPD_WHITE);
    display.fillScreen(GxEPD_BLACK);
    u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set


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


