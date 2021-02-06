#include "mbed.h"

DigitalOut motor_A(D4); //D4はモータAの向きを指定するピン
PwmOut pwm_A(D5);       //D5はモータAの速さを指定するピン

int main(){
    while(1){
        //正転
        motor_A = 1;
        pwm_A = 1.0;
        wait(1);

        //逆転
        motor_A = 0;
        pwm_A = 1.0;
        wait(1);

        //静止
        motor_A = 0;
        pwm_A = 0.0;
        wait(1);
    }
}
