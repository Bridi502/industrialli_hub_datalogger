#include "muxCtrl.h"

void muxCtrl::begin(void)
{

    pinMode(Z_IC01, INPUT);
    pinMode(S0_IC01, OUTPUT);
    pinMode(S1_IC01, OUTPUT);
    pinMode(S2_IC01, OUTPUT);

    pinMode(Z_IC02, INPUT);
    pinMode(S0_IC02, OUTPUT);
    pinMode(S1_IC02, OUTPUT);
    pinMode(S2_IC02, OUTPUT);
}

int muxCtrl::readInput(uint8_t input)
{
    switch (input)
    {
    case 0: // Q1 ->Y4_IC01
        digitalWrite(S0_IC01, LOW);
        digitalWrite(S1_IC01, LOW);
        digitalWrite(S2_IC01, HIGH);
        _Qval[0] = digitalRead(Z_IC01);
        return _Qval[0];
        break;
    case 1: // Q2 ->Y6_IC01
        digitalWrite(S0_IC01, LOW);
        digitalWrite(S1_IC01, HIGH);
        digitalWrite(S2_IC01, HIGH);
        _Qval[1] = digitalRead(Z_IC01);
        return _Qval[1];
        break;
    case 2: // Q3 ->Y5_IC01
        digitalWrite(S0_IC01, HIGH);
        digitalWrite(S1_IC01, LOW);
        digitalWrite(S2_IC01, HIGH);
        _Qval[2] = digitalRead(Z_IC01);
        return _Qval[2];
        break;
    case 3: // Q4 ->Y1_IC01
        digitalWrite(S0_IC01, HIGH);
        digitalWrite(S1_IC01, LOW);
        digitalWrite(S2_IC01, LOW);
        _Qval[3] = digitalRead(Z_IC01);
        return _Qval[3];
        break;

    case 4: // Q5 ->Y7_IC01
        digitalWrite(S0_IC01, HIGH);
        digitalWrite(S1_IC01, HIGH);
        digitalWrite(S2_IC01, HIGH);
        _Qval[4]= digitalRead(Z_IC01);
        return  _Qval[4];
        break;

    case 5: // Q6 ->Y2_IC01
        digitalWrite(S0_IC01, LOW);
        digitalWrite(S1_IC01, HIGH);
        digitalWrite(S2_IC01, LOW);
       _Qval[5] = digitalRead(Z_IC01);
        return _Qval[5];
        break;

    case 6: // Q7 ->Y0_IC01
        digitalWrite(S0_IC01, LOW);
        digitalWrite(S1_IC01, LOW);
        digitalWrite(S2_IC01, LOW);
        _Qval[6] = digitalRead(Z_IC01);
        return _Qval[6];
        break;

    case 7: // Q8 ->Y3_IC01
        digitalWrite(S0_IC01, HIGH);
        digitalWrite(S1_IC01, HIGH);
        digitalWrite(S2_IC01, LOW);
        _Qval[7] = digitalRead(Z_IC01);
        return _Qval[7];
        break;

    case 8: // Q9 ->Y6_IC02
        digitalWrite(S0_IC02, LOW);
        digitalWrite(S1_IC02, HIGH);
        digitalWrite(S2_IC02, HIGH);
        _Qval[8] = digitalRead(Z_IC02);
        return _Qval[8];
        break;

    case 9: // Q10 ->Y5_IC02
        digitalWrite(S0_IC02, HIGH);
        digitalWrite(S1_IC02, LOW);
        digitalWrite(S2_IC02, HIGH);
        _Qval[9]= digitalRead(Z_IC02);
        return _Qval[9];
        break;

    case 10: // Q11 ->Y4_IC02
        digitalWrite(S0_IC02, LOW);
        digitalWrite(S1_IC02, LOW);
        digitalWrite(S2_IC02, HIGH);
        _Qval[10] = digitalRead(Z_IC02);
        return _Qval[10];
        break;

    case 11: // Q12 ->Y7_IC02
        digitalWrite(S0_IC02, HIGH);
        digitalWrite(S1_IC02, HIGH);
        digitalWrite(S2_IC02, HIGH);
        _Qval[11] = digitalRead(Z_IC02);
        return _Qval[11];
        break;

    case 12: // Q13 ->Y1_IC02
        digitalWrite(S0_IC02, HIGH);
        digitalWrite(S1_IC02, LOW);
        digitalWrite(S2_IC02, LOW);
        _Qval[12] = digitalRead(Z_IC02);
        return _Qval[12];
        break;

    case 13: // Q14 ->Y0_IC02
        digitalWrite(S0_IC02, LOW);
        digitalWrite(S1_IC02, LOW);
        digitalWrite(S2_IC02, LOW);
        _Qval[13] = digitalRead(Z_IC02);
        return _Qval[13];
        break;

    case 14: // Q15 ->Y3_IC02
        digitalWrite(S0_IC02, HIGH);
        digitalWrite(S1_IC02, HIGH);
        digitalWrite(S2_IC02, LOW);
       _Qval[14] = digitalRead(Z_IC02);
        return _Qval[14];
        break;

    case 15: // Q16 ->Y2_IC02
        digitalWrite(S0_IC02, LOW);
        digitalWrite(S1_IC02, HIGH);
        digitalWrite(S2_IC02, LOW);
        _Qval[15] = digitalRead(Z_IC02);
        return _Qval[15];
        break;

    default:
        return -1;
        break;
    }
}