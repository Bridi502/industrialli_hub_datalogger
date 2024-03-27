#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "shiftRegisterCtrl.h"
#include "muxCtrl.h"
#include "isoOutputs.h"
#include "anlgOut.h"
#include "INA226.h"


INA226 INA(0x45);
#define I2C2_SCL PA9
#define I2C2_SDA PA8
#define ALRT_ISO PA10
#define ALRT PE8

#define I2C_ADDRESS 0x40
#define I2C_ADDRESS_ISO 0x45



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
  pinMode(ALRT_ISO, INPUT);
  pinMode(ALRT, INPUT);


  SerialUSB.begin(115200);

  srCtrl.begin();
  mxCtrl.begin();
  isoOut.begin();
  anlgOutputs.begin();


  Wire.setSCL(I2C2_SCL);
  Wire.setSDA(I2C2_SDA);
  //Wire.setClock(400000L);
  Wire.begin();

    if (!INA.begin() )
  {
    SerialUSB.println("could not connect. Fix and Reboot");
  }
  INA.setMaxCurrentShunt(1, 0.1);


}

void loop()
{
  // put your main code here, to run repeatedly:
  srCtrl.turnOn(DUT_PWR_ON_OFF);
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

  // SerialUSB.print(mxCtrl.readInput(Q1));
  // SerialUSB.print(" ");
  // SerialUSB.print(mxCtrl.readInput(Q2));
  // SerialUSB.println();

  // delay(1000);

  digitalWrite(LED_DEBUG, !digitalRead(LED_DEBUG));
  // SerialUSB.println("Hello");
  // delay(100);
  SerialUSB.println("\nBUS\tSHUNT\tCURRENT\tPOWER");
  for (int i = 0; i < 20; i++)
  {
    SerialUSB.print(INA.getBusVoltage(), 3);
    SerialUSB.print("\t");
    SerialUSB.print(INA.getShuntVoltage_mV(), 3);
    SerialUSB.print("\t");
    SerialUSB.print(INA.getCurrent_mA(), 3);
    SerialUSB.print("\t");
    SerialUSB.print(INA.getPower_mW(), 3);
    SerialUSB.println();
    delay(1000);
  }

}

// put function definitions here:
