#include <Arduino.h>

#include "RB_class_MENU.h"
#include "RB_functions.h"
#include "RB_defines.h"
#include "button_struct.h"
#include "BluetoothSerial_obj.h"
// #include "Display_print.h"
#include "Display_print_Adafruit_lib.h"


// #include <SPI.h>
// #include "epd2in9_V2.h"
// #include "epdpaint.h"
// #include "imagedata.h"

// Epd epd;

MENU_widget RoadBookApp;

extern GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display;
extern U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;


void setup() {
    Serial.begin(115200);

	pinMode(CLK, INPUT_PULLUP);
	pinMode(DT, INPUT_PULLUP);
	pinMode(SW, INPUT_PULLUP);


    display.init();
    display.setTextColor(GxEPD_BLACK);
    display.firstPage();
    display.setRotation(1);
    delay(1000);

    u8g2Fonts.begin(display); // connect u8g2 procedures to Adafruit GFX
    u8g2Fonts.setForegroundColor(GxEPD_BLACK);         // apply Adafruit GFX color
    u8g2Fonts.setBackgroundColor(GxEPD_WHITE);
    u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set

    RoadBookApp.AppLoop();
}
 



void loop() {
}
