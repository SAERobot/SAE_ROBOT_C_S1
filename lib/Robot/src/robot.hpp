#ifndef ROBOT_HPP
#define ROBOT_HPP

#define WAITING_MODE 0
#define DEBUG_MODE 1
#define CONFETTIS_MODE 2
#define LINE_FOLLOWING_MODE 3
#define SQUARE_MODE 4

#include <mbed.h>

class Robot {

private:
    DigitalIn jack;
    DigitalIn finCourse;
    AnalogIn mesureBatterie;
    AnalogIn captLigneDroiteInt;
    AnalogIn captLigneDroiteExt;
    AnalogIn captLigneGaucheInt;
    AnalogIn captLigneGaucheExt;

public:
    Robot();
    bool boot;
    int mode;

    DigitalOut IHM_Led1;
    DigitalOut IHM_Led2;
    DigitalOut IHM_Led3;
    DigitalOut IHM_Led4;

    DigitalIn IHM_Btn1;
    DigitalIn IHM_Btn2;
    DigitalIn IHM_Btn3;
    DigitalIn IHM_Btn4;

    int jackVal;
    int fcVal;
    double mbVal;
    double dIntVal;
    double dExtVal;
    double gIntVal;
    double gExtVal;

    void debugMode();
    bool isReady();
};


#endif