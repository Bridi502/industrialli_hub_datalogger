#include <Arduino.h>
#include <SPI.h>
#include "shiftRegisterCtrl.h"
#include "muxCtrl.h"
#include "isoOutputs.h"
#include "anlgOut.h"


#define LED_DEBUG PB11
shiftRegisterCtrl srCtrl;
muxCtrl mxCtrl;
isoOutputs isoOut;
anlgOut anlgOutputs;


// put function declarations here:


void setup()
{
  // put your setup code here, to run once:

  pinMode(LED_DEBUG, OUTPUT);
  SerialUSB.begin(115200);

  srCtrl.begin();
  mxCtrl.begin();
  isoOut.begin();
  anlgOutputs.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:

  srCtrl.turnOff(DUT_PWR_ON_OFF);
  srCtrl.turnOn(DUT_ISO_ON_OFF);
  srCtrl.turnOn(RELAY_ANLG_02);
  srCtrl.turnOn(RELAY_ANLG_01);
  srCtrl.turnOff(OD_IC01);
  srCtrl.writeSrOutputs();

  isoOut.turnOn(I01);
  isoOut.turnOn(I04);
  isoOut.turnOn(I07);
  isoOut.turnOn(I08);
  isoOut.writeOutputs();

  anlgOutputs.writeDAC(0, 0);
  anlgOutputs.writeDAC(1, 30000);
  anlgOutputs.writeDAC(2, 30000);
  anlgOutputs.writeDAC(3, 30000);

  SerialUSB.print(mxCtrl.readInput(Q1));
  SerialUSB.print(" ");
  SerialUSB.print(mxCtrl.readInput(Q2));
  SerialUSB.println();

  digitalWrite(LED_DEBUG, !digitalRead(LED_DEBUG));
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}