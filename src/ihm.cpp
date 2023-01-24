#include <mbed.h>
#include "robot.hpp"

DigitalOut IHM_Led1();
DigitalOut IHM_Led2();
DigitalOut IHM_Led3();
DigitalOut IHM_Led4();

DigitalIn IHM_Btn1();
DigitalIn IHM_Btn2();
DigitalIn IHM_Btn3();
DigitalIn IHM_Btn4();

/*
void ihmBoot(Robot& goofyBot) {
    while(goofyBot.boot != true) {
        // a faire
    }
    return;
}
*/