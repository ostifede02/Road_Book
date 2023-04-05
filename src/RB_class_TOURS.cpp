#include "RB_class_TOURS.h"

void ToursWidget::isToursPageCalled(void){
    int number_of_files = 0;
    bool isTourPageOpen = true;

    number_of_files = ReadFilesList();
    while(isTourPageOpen){
        isTourPageOpen = SelectFile(number_of_files);
    }
    return;
}


int ToursWidget::ReadFilesList(void){
    int file_list_index = 0;

    
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return 0;
    }

    root = SPIFFS.open("/");
    file = root.openNextFile();

    file_list_index = 0;
    while(file){
        // file_list_buffer[file_list_index] = '/';
        file_list_buffer[file_list_index] = file.name();

        file = root.openNextFile();
        file_list_index += 1;
    }

    return file_list_index; // returns the number of available files
}

bool ToursWidget::SelectFile(int number_of_files){
    int scroll_file_index = 0;
    String sub_str;


    sub_str = file_list_buffer[scroll_file_index];
    sub_str = sub_str.substring(0, (sub_str.length() - 4));

    PrintOnDisplay(sub_str, TOUR_LABEL_TEXT);

    while(true){
        switch (GetInterruptCommand()){
            case 'r':
                scroll_file_index += 1;
                break;
            case 'l':
                scroll_file_index -= 1;
                break;
            case 'R':
                OpenReadFile(scroll_file_index);
                return true;
            case 'L':
                return false;
            default:
                break;
        }
        scroll_file_index = min(scroll_file_index, number_of_files - 1);
        scroll_file_index = max(scroll_file_index, 0);

        sub_str = file_list_buffer[scroll_file_index];
        sub_str = sub_str.substring(0, (sub_str.length() - 4));

        PrintOnDisplay(sub_str, TOUR_LABEL_TEXT);
    }
}

void ToursWidget::OpenReadFile(int file_index){
    int line_index = 0;
    file = SPIFFS.open('/' + file_list_buffer[file_index]);
    

    while(file.available()){
        file_rows_buffer[line_index] = file.readStringUntil('\n');
        line_index += 1;
    }

    file.close();

    BrowsFileRows(line_index);
    return;
}

void ToursWidget::BrowsFileRows(int number_of_rows){
    int scroll_line_index = 0;

    PrintOnDisplay(file_rows_buffer[0], TOUR_PLAIN_TEXT);


    while(true){
        switch (GetInterruptCommand()){
            case 'r':
                scroll_line_index += 1;
                break;
            case 'l':
                scroll_line_index -= 1;
                break;
            case 'L':
                return;
            default:
                break;
        }
        scroll_line_index = min(scroll_line_index, number_of_rows - 1);
        scroll_line_index = max(scroll_line_index, 0);

        PrintOnDisplay(file_rows_buffer[scroll_line_index], TOUR_PLAIN_TEXT);
    }
}