#include "anlgOut.h"
void anlgOut::begin(void)
{

    pinMode(SYNC_DAC_01, OUTPUT);
    pinMode(SYNC_DAC_02, OUTPUT);
    pinMode(SYNC_DAC_03, OUTPUT);
    pinMode(SYNC_DAC_04, OUTPUT);

    pinMode(EF_IC01, INPUT);
    pinMode(EF_IC02, INPUT);
    pinMode(EF_IC03, INPUT);
    pinMode(EF_IC04, INPUT);
}

void anlgOut::writeDAC(uint8_t dac, int data)
{
    switch (dac)
    {
    case 0:
    {
        _spiPort = &SPI;
        _spiPort->setMISO(SPI1_MISO);
        _spiPort->setMOSI(SPI1_MOSI);
        _spiPort->setSCLK(SPI1_SCK);
        _spiPort->begin();
        _spiPort->beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE2));

        uint16_t dataBuf[3] = {mode,                                // dataBuf[0] MSB
                               ((uint16_t)data & 0x0000FF00) >> 8,  // dataBuf[1] MID
                               ((uint16_t)data & 0x000000FF) >> 0}; // dataBuf[2] LSB

        digitalWrite(SYNC_DAC_01, LOW);
        _spiPort->transfer(dataBuf[0]);
        _spiPort->transfer(dataBuf[1]);
        _spiPort->transfer(dataBuf[2]);
        digitalWrite(SYNC_DAC_01, HIGH);

        _spiPort->endTransaction();
        _spiPort->end();
        break;
    }
    case 1:
    {
                _spiPort = &SPI;
        _spiPort->setMISO(SPI1_MISO);
        _spiPort->setMOSI(SPI1_MOSI);
        _spiPort->setSCLK(SPI1_SCK);
        _spiPort->begin();
        _spiPort->beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE2));

        uint16_t dataBuf[3] = {mode,                                // dataBuf[0] MSB
                               ((uint16_t)data & 0x0000FF00) >> 8,  // dataBuf[1] MID
                               ((uint16_t)data & 0x000000FF) >> 0}; // dataBuf[2] LSB

        digitalWrite(SYNC_DAC_02, LOW);
        _spiPort->transfer(dataBuf[0]);
        _spiPort->transfer(dataBuf[1]);
        _spiPort->transfer(dataBuf[2]);
        digitalWrite(SYNC_DAC_02, HIGH);

        _spiPort->endTransaction();
        _spiPort->end();
    break;
    }
    case 2:
    {
                _spiPort = &SPI;
        _spiPort->setMISO(SPI1_MISO);
        _spiPort->setMOSI(SPI1_MOSI);
        _spiPort->setSCLK(SPI1_SCK);
        _spiPort->begin();
        _spiPort->beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE2));

        uint16_t dataBuf[3] = {mode,                                // dataBuf[0] MSB
                               ((uint16_t)data & 0x0000FF00) >> 8,  // dataBuf[1] MID
                               ((uint16_t)data & 0x000000FF) >> 0}; // dataBuf[2] LSB

        digitalWrite(SYNC_DAC_03, LOW);
        _spiPort->transfer(dataBuf[0]);
        _spiPort->transfer(dataBuf[1]);
        _spiPort->transfer(dataBuf[2]);
        digitalWrite(SYNC_DAC_03, HIGH);

        _spiPort->endTransaction();
        _spiPort->end();
    break;
    }
    case 3:
    {
                _spiPort = &SPI;
        _spiPort->setMISO(SPI1_MISO);
        _spiPort->setMOSI(SPI1_MOSI);
        _spiPort->setSCLK(SPI1_SCK);
        _spiPort->begin();
        _spiPort->beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE2));

        uint16_t dataBuf[3] = {mode,                                // dataBuf[0] MSB
                               ((uint16_t)data & 0x0000FF00) >> 8,  // dataBuf[1] MID
                               ((uint16_t)data & 0x000000FF) >> 0}; // dataBuf[2] LSB

        digitalWrite(SYNC_DAC_04, LOW);
        _spiPort->transfer(dataBuf[0]);
        _spiPort->transfer(dataBuf[1]);
        _spiPort->transfer(dataBuf[2]);
        digitalWrite(SYNC_DAC_04, HIGH);

        _spiPort->endTransaction();
        _spiPort->end();
    break;
    }

    default:
        break;
    }
}