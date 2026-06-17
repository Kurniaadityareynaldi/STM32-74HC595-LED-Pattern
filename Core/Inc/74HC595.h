#ifndef __LED_h__
#define __LED_h__

#include "main.h"

#define clockPin       clock_Pin
#define serialDataPin  data_Pin
#define latchPin       latch_Pin
#define ShiftRegister74HC595_GPIO_Port GPIOA
#define Number_of_Registers    3

typedef enum
{
  LOW595 = 0U,
  HIGH595
}PinState595;

typedef enum
{
  LOW = 0,
  HIGH
}bool;

//extern unsigned char  shiftRegisters[];

void SerialDataPinSet(PinState595 state);
void ClockPinSet(PinState595 state);
void LatchPinSet(PinState595 state);
void ShiftRegister74HC595_clear(void);
void ShiftRegister74HC595_on(void);
void ShiftRegister74HC595_setAll(bool val);
void ShiftRegister74HC595_setPin(int index, bool val);
void ShiftRegister74HC595_update(void);
void pattern_panah_kiri();
void pattern_silang();
void pattern_panah_kanan();
void ShiftRegister74HC595_init(void);
#endif
