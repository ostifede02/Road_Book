#include "Display_print_Adafruit_lib.h"

// GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=5*/ 2, /*DC=*/ 32, /*RST=*/ 4, /*BUSY=*/ 25));
GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=5*/ 2, /*DC=*/ 32, /*RST=*/ 4, /*BUSY=*/ 25));
U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;


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
    input_str.toCharArray(str_to_print, input_str.length()+1);

    display.setPartialWindow(30, 52, 250, 30); //30, 76, 200, 24
    u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set
    display.firstPage();

    do{
        display.fillScreen(GxEPD_WHITE);
        u8g2Fonts.setCursor(32, 76);
        u8g2Fonts.print(str_to_print);
    }while(display.nextPage());
    return;
}


void TourFilesLabel(String input_str){
    char str_to_print[MAX_DISPLAY_STRING_LENGTH];
    input_str.toCharArray(str_to_print, input_str.length()+1);

    display.setPartialWindow(30, 52, 250, 30);
    u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set
    display.firstPage();

    do{
        display.fillScreen(GxEPD_WHITE);
        u8g2Fonts.setCursor(32, 76);             //cursor(x,y)
        u8g2Fonts.print(str_to_print);   //print the text
    }while (display.nextPage());
    return;
}


void PlainTextLabel(String input_str){
    char str_to_print[MAX_DISPLAY_STRING_LENGTH];
    String sub_str;

    Serial.println("pass 1");

    u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set

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

            display.setPartialWindow(0, 24*row, 296, 24);
            u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set
            display.firstPage();

            do{
                display.fillScreen(GxEPD_WHITE);
                u8g2Fonts.setCursor(0, row*24);             //cursor(x,y)
                u8g2Fonts.print(str_to_print);   //print the text
            }while (display.nextPage());

            row += 1;
            start = end + 1; // aggiorna l'indice di partenza
        }
        end++;
    }
    
    sub_str = input_str.substring(start); // stampa l'ultima sottostringa
    sub_str.toCharArray(str_to_print, sub_str.length() + 1);
    str_to_print[sub_str.length()-1] = '\0';

    display.setPartialWindow(0, 24*row, 296, 24);
    u8g2Fonts.setFont(u8g2_font_fub20_tr);   //font is set
    display.firstPage();

    do{
        display.fillScreen(GxEPD_WHITE);
        u8g2Fonts.setCursor(0, row*24);             //cursor(x,y)
        u8g2Fonts.print(str_to_print);   //print the text
    }while (display.nextPage());

    return;
}


