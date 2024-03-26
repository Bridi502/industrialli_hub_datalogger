#include "shiftRegisterCtrl.h" 

void shiftRegisterCtrl::begin(){
pinMode(STPC, OUTPUT);//sr pin 12
pinMode(SHCP, OUTPUT);//sr pin 11
pinMode(DS, OUTPUT);//sr pin 14
}

void shiftRegisterCtrl::turnOn(uint8_t pin){
    _pin = pin;
_srOutput[_pin] = 1;

}

void shiftRegisterCtrl::turnOff(uint8_t pin){
    _pin = pin;
    _srOutput[_pin] = 0;


}
void shiftRegisterCtrl::writeSrOutputs(void){

uint8_t srOutput[8] = {
    _srOutput[0],
    _srOutput[1],
    _srOutput[2], 
    _srOutput[3],
    _srOutput[4],
    _srOutput[5],
    _srOutput[6],
    _srOutput[7]
};
digitalWrite(STPC, LOW);
  _buffer += (srOutput[0] << 7);
  _buffer += (srOutput[1] << 6);
  _buffer += (srOutput[2] << 5);
  _buffer += (srOutput[3] << 4);
  _buffer += (srOutput[4] << 3);
  _buffer += (srOutput[5] << 2);
  _buffer += (srOutput[6] << 1);
  _buffer += (srOutput[7] << 0);
  shiftOut(DS, SHCP, LSBFIRST, _buffer);
  digitalWrite(STPC, HIGH);
  _buffer = 0;
}