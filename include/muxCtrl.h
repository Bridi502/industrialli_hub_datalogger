#ifndef MUXCTRL_H
#define MUXCTRL_H
#include <Arduino.h>
#include <stdlib.h>

#define Z_IC01	PC7
#define S0_IC01	PC12
#define S1_IC01	PD0
#define S2_IC01	PD1

#define Z_IC02	PD2
#define S0_IC02	PD3
#define S1_IC02	PD10
#define S2_IC02	PD11

#define Q1 0
#define Q2 1
#define Q3 2
#define Q4 3
#define Q5 4
#define Q6 5
#define Q7 6
#define Q8 7

#define Q9 8
#define Q10 9
#define Q11 10
#define Q12 11
#define Q13 12
#define Q14 13
#define Q15 14
#define Q16 15

class muxCtrl
{
private:
uint8_t _Qval[16] = {
_Qval[0] = 0,
_Qval[1] = 0, 
_Qval[2] = 0, 
_Qval[3] = 0, 
_Qval[4] = 0, 
_Qval[5] = 0,  
_Qval[6] = 0, 
_Qval[7] = 0, 
_Qval[8] = 0, 
_Qval[9] = 0, 
_Qval[10] = 0, 
_Qval[11] = 0, 
_Qval[12] = 0, 
_Qval[13] = 0, 
_Qval[14] = 0, 
_Qval[15] = 0 
};
public:
void begin(void);
int readInput(uint8_t input);
};







#endif