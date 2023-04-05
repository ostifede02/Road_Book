#include "RB_class_MENU.h"

void MENU_widget::MenuInit(void){
    return;
}

void MENU_widget::AppLoop(void){
    MenuInit();
    
    char cmd;
    int menu_index = 0;

    while (true){
        PrintOnDisplay(menu_pages[menu_index], MENU_TEXT);

        switch (GetInterruptCommand()){
            case 'r':
                menu_index += 1;
                break;
            case 'l':
                menu_index -= 1;
                break;
            case 'R':
                OpenWidget(menu_index);
                break;
            case 'L':
                /* code */
                break;       
            default:
                break;
        }
        
        if(menu_index < 0){
            menu_index = NUMBER_MENU_PAGES-1;
        }
        else if(menu_index >= NUMBER_MENU_PAGES){
            menu_index = 0;
        }
    }
    
}


void MENU_widget::OpenWidget(int widget_index){
    /*
    The MENU label will have the following structure:
        widget_index == 0       ->      TOURS
        widget_index == 1       ->      TEMPERATURE
        widget_index == 2       ->      SPEED
    */

    switch(widget_index){
        case 0:
            ToursPage.isToursPageCalled();
            break;
        case 1:
            Serial.println("\n\nThe page TEMPERATURE has been selected, but it still does nothing :(\n\n");
            break;
        case 2:
            Serial.println("\n\nThe page SPEED has been selected, but it still does nothing :(\n\n");
            break;
        default:
            break;
    }

    return;
}
