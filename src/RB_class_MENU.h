#include "RB_class_TOURS.h"
#include "RB_defines.h"
#include "RB_functions.h"
#include "Display_print_Adafruit_lib.h"
// #include "Display_print.h"


class MENU_widget{    
    private:
        ToursWidget ToursPage;
        String menu_pages[NUMBER_MENU_PAGES] = {"TOURS", "TEMPERATURE", "SPEED"}; // ATTENTION: CHANGE NUMBER OF PAGES
        void MenuInit(void);
        void OpenWidget(int widget_index);

    public:
        void AppLoop(void);
};