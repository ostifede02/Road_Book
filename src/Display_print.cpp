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

    paint.DrawStringAt(80, 0, str_to_print, &Font24, COLORED);

    epd.SetFrameMemory(paint.GetImage(), 52, 0, paint.GetWidth(), paint.GetHeight());
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

    paint.DrawStringAt(5, 0, str_to_print, &Font20, COLORED);

    epd.SetFrameMemory(paint.GetImage(), 54, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();
    
    return;
}


void PlainTextLabel(String input_str){
    char str_to_print[MAX_DISPLAY_STRING_LENGTH];
    String sub_str;

    if (epd.Init() != 0) {
        Serial.println("e-Paper init failed");
        return;
    }

    epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
    epd.DisplayFrame_Partial();

    paint.SetRotate(ROTATE_90);
    paint.SetWidth(128); //120
    paint.SetHeight(296); //24

    paint.Clear(UNCOLORED);

    int start = 0, end = 0, row = 0;
    while (end < input_str.length()) { // finché non si arriva alla fine della stringa
        if (end - start + 1 > 21 || input_str[end] == '\n') { // se la sottostringa supera i 21 caratteri o si raggiunge una nuova linea
            if (input_str[end] != '\n') { // se l'ultimo carattere non è una nuova linea
                while (input_str[end] != ' ') { // cerca l'ultimo spazio prima della nuova linea
                    end--;
                }
            }
            sub_str = input_str.substring(start, end); // stampa la sottostringa
            sub_str.toCharArray(str_to_print, sub_str.length() + 1);
            paint.DrawStringAt(0, 20*row + 5, str_to_print, &Font20, COLORED);

            row += 1;
            start = end + 1; // aggiorna l'indice di partenza
        }
        end++;
    }
    
    sub_str = input_str.substring(start); // stampa l'ultima sottostringa
    sub_str.toCharArray(str_to_print, sub_str.length() + 1);
    str_to_print[sub_str.length()-1] = '\0';

    paint.DrawStringAt(0, 20*row + 5, str_to_print, &Font20, COLORED);

    epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame_Partial();
}

