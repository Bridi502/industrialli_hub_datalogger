#ifndef ISOOUTPUTS_H
#define ISOOUTPUTS_H
#include <Arduino.h>
#include <stdlib.h>
#include <SPI.h>
#include "pinout.h"

#define ISO_DIS PD12
#define ISO_CS PD13
#define ISO_DIAG PD14

#define I01 0
#define I02 1
#define I03 2
#define I04 3
#define I05 4
#define I06 5
#define I07 6
#define I08 7

class isoOutputs
{
private:
    SPIClass *_spiPort;
    uint8_t _output;
    uint8_t _transferIsoOut0to7 = 0;
    uint8_t _isoDigitalOutput[8] = {
        _isoDigitalOutput[0] = 0,
        _isoDigitalOutput[1] = 0,
        _isoDigitalOutput[2] = 0,
        _isoDigitalOutput[3] = 0,
        _isoDigitalOutput[4] = 0,
        _isoDigitalOutput[5] = 0,
        _isoDigitalOutput[6] = 0,
        _isoDigitalOutput[7] = 0};

public:
    void begin(void);
    void turnOn(uint8_t output);
    void turnOff(uint8_t output);
    void writeOutputs(void);
};

#endif