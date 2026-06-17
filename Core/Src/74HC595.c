#include "74HC595.h"


void delay(uint32_t count)
{
    for (uint32_t i = 0; i < count; i++);
}

unsigned char  shiftRegisters[3] = {0}; //3 means 3 74HC595 IC

void ShiftRegister74HC595_dalay(void)
{
    unsigned int i;
    for(i = 0; i < 10000; i ++);
}
//IO init

void ShiftRegister74HC595_init(void)
{
//set your IO
}

void ShiftRegister74HC595_update(void)
{
    //Set and display registers
	//Only call AFTER all values are set how you would like
    int i , j;
    LatchPinSet(LOW595);

    //iterate through the registers
    for(i = Number_of_Registers - 1; i >=  0; i--){

        //iterate through the bits in each registers
        for(j = 8 - 1; j >=  0; j--){
            ClockPinSet(LOW595);

            int val = shiftRegisters[i] & (1 << j);

            SerialDataPinSet((PinState595)val);
            ClockPinSet(HIGH595);
        }
    }
		LatchPinSet(HIGH595);
}

void ShiftRegister74HC595_setPin(int index, bool val)
{
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    unsigned char current_byte = shiftRegisters[byteIndex];

    current_byte &= ~(1 << bitIndex);   //clear the bit need to be set
    current_byte |= val << bitIndex;    //set the bit

    shiftRegisters[byteIndex] = current_byte;
}

void pattern_panah_kiri()
{
	HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, mr_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, oe_Pin, GPIO_PIN_RESET);

	  shiftRegisters[0] = 0x03;
  	  shiftRegisters[2] = 0x7F;
  	  ShiftRegister74HC595_update();

  	  shiftRegisters[0] = 0x3F;
  	  shiftRegisters[2] = 0xBF;
 	  ShiftRegister74HC595_update();

  	  shiftRegisters[0] = 0x5F;
  	  shiftRegisters[2] = 0xDF;
  	  ShiftRegister74HC595_update();

  	  shiftRegisters[0] = 0x6F;
  	  shiftRegisters[2] = 0xEF;
 	  ShiftRegister74HC595_update();

  	  shiftRegisters[0] = 0x77;
  	  shiftRegisters[2] = 0xF7;
  	  ShiftRegister74HC595_update();

  	  shiftRegisters[0] = 0x7B;
  	  shiftRegisters[2] = 0xFB;
 	  ShiftRegister74HC595_update();

  	  shiftRegisters[0] = 0xFD;
  	  shiftRegisters[2] = 0xFD;
 	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xFE;
	  shiftRegisters[2] = 0xFE;
	  ShiftRegister74HC595_update();
}

void pattern_silang()
{
	HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, mr_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, oe_Pin, GPIO_PIN_RESET);

	shiftRegisters[1] = 0x7E;
	shiftRegisters[2] = 0x7F;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0xBD;
	shiftRegisters[2] = 0xBF;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0xDB;
	shiftRegisters[2] = 0xDF;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0xE7;
	shiftRegisters[2] = 0xEF;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0xE7;
	shiftRegisters[2] = 0xF7;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0xDB;
	shiftRegisters[2] = 0xFB;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0xBD;
	shiftRegisters[2] = 0xFD;
	ShiftRegister74HC595_update();

	shiftRegisters[1] = 0x7E;
	shiftRegisters[2] = 0xFE;
	ShiftRegister74HC595_update();
}

void pattern_panah_kanan()
{
	HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, mr_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, oe_Pin, GPIO_PIN_RESET);

	  shiftRegisters[0] = 0xC0;
	  shiftRegisters[2] = 0x7F;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xFC;
	  shiftRegisters[2] = 0xBF;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xFA;
	  shiftRegisters[2] = 0xDF;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xF6;
	  shiftRegisters[2] = 0xEF;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xEE;
	  shiftRegisters[2] = 0xF7;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xDE;
	  shiftRegisters[2] = 0xFB;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0xBF;
	  shiftRegisters[2] = 0xFD;
	  ShiftRegister74HC595_update();

	  shiftRegisters[0] = 0x7F;
	  shiftRegisters[2] = 0xFE;
	  ShiftRegister74HC595_update();
}


void ShiftRegister74HC595_clear(void){
	shiftRegisters[0] = 0xFF; // 1111 1111
	shiftRegisters[1] = 0xFF;
	shiftRegisters[2] = 0xFF;
	ShiftRegister74HC595_update();
}

void ShiftRegister74HC595_on(void){
	shiftRegisters[0] = 0x00; // 1111 1111
	shiftRegisters[1] = 0x00;
	shiftRegisters[2] = 0x00;
	ShiftRegister74HC595_update();
}

void ShiftRegister74HC595_setAll(bool val)
{
    int i;
    //set all register pins to val
    for(i = Number_of_Registers * 8 - 1; i >=  0; i--){
        ShiftRegister74HC595_setPin(i, val);
    }
		ShiftRegister74HC595_update();
}

void LatchPinSet(PinState595 state)
{
    HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, latchPin, (GPIO_PinState)state);
}

void ClockPinSet(PinState595 state)
{
    HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, clockPin, (GPIO_PinState)state);
}

void SerialDataPinSet(PinState595 state)
{
    HAL_GPIO_WritePin(ShiftRegister74HC595_GPIO_Port, serialDataPin, (GPIO_PinState)state);
}
