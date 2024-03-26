#include "isoOutputs.h"

void isoOutputs::begin(void)
{

    pinMode(ISO_CS, OUTPUT);
    pinMode(ISO_DIS, OUTPUT);
    pinMode(ISO_DIAG, INPUT);
    digitalWrite(ISO_DIS, HIGH); // DIS HIGH -> ENABLE
}
void isoOutputs::turnOn(uint8_t output)
{
    _output = output;
    _isoDigitalOutput[_output] = 1;
}

void isoOutputs::turnOff(uint8_t output)
{
    _output = output;
    _isoDigitalOutput[_output] = 0;
}
void isoOutputs::writeOutputs(void)
{
    _spiPort = &SPI;
    _spiPort->setMISO(SPI1_MISO);
    _spiPort->setMOSI(SPI1_MOSI);
    _spiPort->setSCLK(SPI1_SCK);
    _spiPort->begin();
    _spiPort->beginTransaction(SPISettings(1000000UL, LSBFIRST, SPI_MODE3));

    for (int i = 0; i < 8; i++)
    {
        _transferIsoOut0to7 += (_isoDigitalOutput[i] << (7 - i));
    }

    digitalWrite(ISO_CS, LOW);
    _spiPort->transfer(_transferIsoOut0to7); // LED0 -> LED7
    _transferIsoOut0to7 = 0;
    digitalWrite(ISO_CS, HIGH);
    _spiPort->endTransaction();
    _spiPort->end();
}