#ifndef ANLGOUT_H
#define ANLGOUT_H
#include <Arduino.h>
#include <stdlib.h>
#include <SPI.h>
#include "pinout.h"

#define SYNC_DAC_04	PB5
#define SYNC_DAC_03	PB6
#define SYNC_DAC_02	PB9
#define SYNC_DAC_01	PE0

#define EF_IC03	PE1
#define EF_IC04	PC3
#define EF_IC02	PF2
#define EF_IC01	PE7


class anlgOut
{
private:
SPIClass *_spiPort;
uint16_t mode = 65536;

public:
void begin(void);
void writeDAC(uint8_t dac, int data);



};



#endif