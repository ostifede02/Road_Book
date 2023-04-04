#ifndef BUTTON_STRUCT
#define BUTTON_STRUCT

struct Button
{
    int PIN;
    int time_pressed;
};

extern Button LX_button;
extern Button RX_button;


#endif