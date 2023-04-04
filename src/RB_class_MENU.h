#include "RB_class_TOURS.h"
#include "RB_defines.h"
#include "RB_functions.h"
#include "Display_print.h"

extern unsigned char image[];
extern Paint paint;    // width should be the multiple of 8 
extern Epd epd;


class MENU_widget{    
    private:
        ToursWidget ToursPage;
        String menu_pages[NUMBER_MENU_PAGES] = {"TOURS", "TEMPERATURE", "SPEED"}; // ATTENTION: CHANGE NUMBER OF PAGES
        void MenuInit(void);
        void OpenWidget(int widget_index);

    public:
        void AppLoop(void);
};