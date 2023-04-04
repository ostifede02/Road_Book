#include "Display_print.h"

unsigned char image[37888];
Paint paint(image, 0, 0);    // width should be the multiple of 8 
Epd epd;


void PrintOnDisplay(String input_str, int text_layout){

    switch(text_layout){
        case MENU_TEXT:
            MenuLabel(input_str);
            break; 
        case TOUR_LABEL_TEXT:
            TourFilesLabel(input_str);
            break;
        case TOUR_PLAIN_TEXT:
            PlainTextLabel(input_str);
            break;
        default:
            break;
    }

    return;
}


void MenuLabel(String input_str){
    char str_to_print[MAX_DISPLAY_STRING_LENGTH];

    for(int i=0; i<input_str.length(); ++i){
        str_to_print[i] = input_str[i];
    }
    str_to_print[input_str.length()] = '\0';

    if (epd.Init() != 0) {
        Serial.println("e-Paper init failed");
        return;
    }

    epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
    epd.DisplayFrame();

    paint.SetRotate(ROTATE_90);
    paint.SetWidth(20); 
    paint.SetHeight(296);

    paint.Clear(UNCOLORED);

    paint.DrawStringAt(20, 0, str_to_print, &Font20, COLORED);

    epd.SetFrameMemory(paint.GetImage(), 74, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();

    return;
}


void TourFilesLabel(String input_str){
    char str_to_print[MAX_DISPLAY_STRING_LENGTH];

    for(int i=0; i<input_str.length(); ++i){
        str_to_print[i] = input_str[i];
    }
    str_to_print[input_str.length()] = '\0';

    if (epd.Init() != 0) {
        Serial.println("e-Paper init failed");
        return;
    }

    epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
    epd.DisplayFrame();

    paint.SetRotate(ROTATE_90);
    paint.SetWidth(20); 
    paint.SetHeight(296);

    paint.Clear(UNCOLORED);

    paint.DrawStringAt(0, 20, str_to_print, &Font20, COLORED);

    epd.SetFrameMemory(paint.GetImage(), 74, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();
    
    return;
}


void PlainTextLabel(String input_str){
    char str_to_print[MAX_DISPLAY_STRING_LENGTH];
    char str_row[MAX_CHAR_ROW];
    char sub_str_to_print[MAX_CHAR_ROW];

    for(int i=0; i<input_str.length(); ++i){
        str_to_print[i] = input_str[i];
    }
    str_to_print[input_str.length()] = '\0';

    if (epd.Init() != 0) {
        Serial.println("e-Paper init failed");
        return;
    }

    epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
    epd.DisplayFrame();

    paint.SetRotate(ROTATE_90);
    paint.SetWidth(128); //120
    paint.SetHeight(296); //24

    paint.Clear(UNCOLORED);


    int total_rows = (input_str.length() / MAX_CHAR_ROW) +1;
    int end_row_char_index;

    for(int row_index = 1; row_index <= total_rows; row_index++){
        end_row_char_index  = row_index * MAX_CHAR_ROW;
        while(str_to_print[end_row_char_index] != ' '){
            end_row_char_index -= 1;
        }
        for(int sub_str_index = (row_index-1) * MAX_CHAR_ROW; sub_str_index < row_index * MAX_CHAR_ROW; sub_str_index++){
            sub_str_to_print[sub_str_index - MAX_CHAR_ROW * row_index] = input_str[sub_str_index];
        }

        paint.DrawStringAt(0, 25 * (row_index-1), sub_str_to_print, &Font20, COLORED);
    }

    epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();
}


void Print(char str_to_print[]){
    return;
}

