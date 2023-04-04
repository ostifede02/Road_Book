#ifndef RB_CLASS
#define RB_CLASS

#include "SPIFFS.h"

#include "RB_defines.h"
#include "RB_functions.h"
#include "Display_print.h"

extern unsigned char image[];
extern Paint paint;    // width should be the multiple of 8 
extern Epd epd;

class ToursWidget{
    private:
        File file;
        File root;

        String file_list_buffer[MAX_FILES_AMOUNT];
        String file_rows_buffer[MAX_FILE_LINES];


        bool SelectFile(int number_of_files);
        void OpenReadFile(int file_index);
        void BrowsFileRows(int number_of_rows);
        int ReadFilesList(void);

    public:
        void isToursPageCalled(void);
};




#endif
