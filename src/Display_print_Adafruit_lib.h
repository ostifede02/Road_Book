#ifndef DISPLAY_PRINT_ADAFRUIT
#define DISPLAY_PRINT_ADAFRUIT

#include "RB_defines.h"

#include <GxEPD2_BW.h> // including both doesn't use more code or ram
#include <GxEPD2_3C.h> // including both doesn't use more code or ram
#include <U8g2_for_Adafruit_GFX.h>


void PrintOnDisplay(String input_str, int text_layout);
void MenuLabel(String input_str);
void TourFilesLabel(String input_str);
void PlainTextLabel(String input_str);

#endif