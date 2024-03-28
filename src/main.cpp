#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "shiftRegisterCtrl.h"
#include "muxCtrl.h"
#include "isoOutputs.h"
#include "anlgOut.h"
#include <INA226_WE.h>

#define I2C2_SCL PA9
#define I2C2_SDA PA8
#define ALRT_ISO PA10
#define ALRT PE8

#define I2C_ADDRESS 0x40
#define I2C_ADDRESS_ISO 0x45

INA226_WE INA226_DUT_PWR = INA226_WE(I2C_ADDRESS);
INA226_WE INA226_DUT_PWR_ISO = INA226_WE(I2C_ADDRESS_ISO);

#define LED_DEBUG PB11
shiftRegisterCtrl srCtrl;
muxCtrl mxCtrl;
isoOutputs isoOut;
anlgOut anlgOutputs;





// put function declarations here:
void displayResults();
void displayResultsIso();

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

  INA226_DUT_PWR.init();
  INA226_DUT_PWR_ISO.init();

  INA226_DUT_PWR.setResistorRange(0.1, 1.00);
  INA226_DUT_PWR_ISO.setResistorRange(0.002, 5.00);

  INA226_DUT_PWR.setAverage(AVERAGE_1024);
  INA226_DUT_PWR_ISO.setAverage(AVERAGE_1024);

  INA226_DUT_PWR.setConversionTime(CONV_TIME_8244);
  INA226_DUT_PWR_ISO.setConversionTime(CONV_TIME_8244);

  INA226_DUT_PWR.waitUntilConversionCompleted(); 
  INA226_DUT_PWR_ISO.waitUntilConversionCompleted(); 

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

  
  // SerialUSB.println("Hello");
  // delay(100);

    INA226_DUT_PWR.readAndClearFlags(); // reads interrupt and overflow flags and deletes them 
    displayResults();


  
      digitalWrite(LED_DEBUG, !digitalRead(LED_DEBUG));
    INA226_DUT_PWR_ISO.readAndClearFlags(); // reads interrupt and overflow flags and deletes them 
    displayResultsIso();
  
  delay(100);



}

// put function definitions here:


void displayResults(){
  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0; 
  
  shuntVoltage_mV = INA226_DUT_PWR.getShuntVoltage_mV();
  busVoltage_V = INA226_DUT_PWR.getBusVoltage_V();
  current_mA = INA226_DUT_PWR.getCurrent_mA();
  power_mW = INA226_DUT_PWR.getBusPower();
  loadVoltage_V  = busVoltage_V + (shuntVoltage_mV/1000);
    
  SerialUSB.print("Shunt Voltage [mV]: "); SerialUSB.println(shuntVoltage_mV);
  SerialUSB.print("Bus Voltage [V]: "); SerialUSB.println(busVoltage_V);
  SerialUSB.print("Load Voltage [V]: "); SerialUSB.println(loadVoltage_V);
  SerialUSB.print("Current[mA]: "); SerialUSB.println(current_mA);
  SerialUSB.print("Bus Power [mW]: "); SerialUSB.println(power_mW);
  if(!INA226_DUT_PWR.overflow){
    SerialUSB.println("Values OK - no overflow");
  }
  else{
    SerialUSB.println("Overflow! Choose higher current range");
  }
  SerialUSB.println();
}

void displayResultsIso(){
  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0; 
  
  shuntVoltage_mV = INA226_DUT_PWR_ISO.getShuntVoltage_mV();
  busVoltage_V = INA226_DUT_PWR_ISO.getBusVoltage_V();
  current_mA = INA226_DUT_PWR_ISO.getCurrent_mA();
  power_mW = INA226_DUT_PWR_ISO.getBusPower();
  loadVoltage_V  = busVoltage_V + (shuntVoltage_mV/1000);
    
  SerialUSB.print("Shunt Voltage Iso [mV]: "); SerialUSB.println(shuntVoltage_mV);
  SerialUSB.print("Bus Voltage [V]: "); SerialUSB.println(busVoltage_V);
  SerialUSB.print("Load Voltage [V]: "); SerialUSB.println(loadVoltage_V);
  SerialUSB.print("Current[mA]: "); SerialUSB.println(current_mA);
  SerialUSB.print("Bus Power [mW]: "); SerialUSB.println(power_mW);
  if(!INA226_DUT_PWR_ISO.overflow){
    SerialUSB.println("Values OK - no overflow");
  }
  else{
    SerialUSB.println("Overflow! Choose higher current range");
  }
  SerialUSB.println();
}
