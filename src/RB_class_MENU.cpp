#include "RB_class_MENU.h"

void MENU_widget::MenuInit(void){
    return;
}

// struct event{
//     char command;
//     bool consumed;
// };

// struct tab_data{
//     String string;
//     int font;
//     int size;
//     int label;
// };

// void tour(event* e, tab_data* data){
//     data->font = 1;
//     data->string = "In Tour";

//     if(e->consumed == false){
//         if(e->command == 'R'){
//             // Read Files
//             e->consumed = true;
//         }else if(e->command == 'L'){
//             // 
//             e->consumed = false;
//         }
//     }
// }
// void temp(event* e){
//     e->consumed = false;
// }

// void tabManager(event* e){
//     int index = 0; // tab index
//     switch (index)
//     {
//     case 0:
//         tour(e);
//         break;
//     case 1:
//         temp(e);
//         break;
//     default:
//         break;
//     }
//     if(e->consumed == false){
//         // do stuff with command
//         // if the commad is used set consumed to true
//         if(e->command == 'r'){
//             e->consumed = true;
//         }
//     }
// }

void MENU_widget::AppLoop(void){
    MenuInit();
    
    char cmd;
    int menu_index = 0;

    // event e;

    while (true){
    //     e.command = GetInterruptCommand();
    //     e.consumed = false;
    //     tabManager(&e);
    //     if(e.consumed == false){
    //         // use the command
    //     }

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
                PrintOnDisplay(" ", MENU_TEXT);
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
