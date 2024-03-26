#ifndef SHIFTREGISTERCTRL_H
#define SHIFTREGISTERCTRL_H
#include <Arduino.h>
#include <stdlib.h>

#define SHCP PA4  // sr pin 11
#define STPC PD15 // sr pin 12
#define DS PB4    // sr pin 14

#define DUT_PWR_ON_OFF 0
#define OD_IC01 1
#define OD_IC02 2
#define OD_IC04 3
#define OD_IC03 4
#define RELAY_ANLG_02 5
#define RELAY_ANLG_01 6
#define DUT_ISO_ON_OFF 7



class shiftRegisterCtrl
{
private:
    uint8_t _pin;
    uint8_t _srOutput[8] = {
        _srOutput[0] = 0,
        _srOutput[1] = 0,
        _srOutput[2] = 0,
        _srOutput[3] = 0,
        _srOutput[4] = 0,
        _srOutput[5] = 0,
        _srOutput[6] = 0,
        _srOutput[7] = 0};
    uint8_t _buffer = 0;

public:
    void begin();
    void turnOn(uint8_t pin);
    void turnOff(uint8_t pin);
    void writeSrOutputs(void);
};

#endif