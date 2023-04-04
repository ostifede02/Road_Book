#ifndef DISPLAY_PRINT
#define DISPLAY_PRINT

#include <SPI.h>
#include "epd2in9_V2.h"
#include "epdpaint.h"
#include "imagedata.h"

#include "RB_defines.h"

void PrintOnDisplay(String input_str, int text_layout);
void MenuLabel(String input_str);
void TourFilesLabel(String input_str);
void PlainTextLabel(String input_str);

#endif