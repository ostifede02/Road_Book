#ifndef RB_FUNCTIONS
#define RB_FUNCTIONS

#include "BluetoothSerial.h"
#include "RB_defines.h"


char GetInterruptCommand(void);
void LX_ButtonISR(void);
void RX_ButtonISR(void);

#endif