#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <mbed.h>

class Robot {

private:
    DigitalIn jack;
    DigitalIn finCourse;
    AnalogIn mesureBatterie;
    AnalogIn captLigneDroite1;
    AnalogIn captLigneDroite2;
    AnalogIn captLigneGauche1;
    AnalogIn captLigneGauche2;

public:
    Robot();
    bool boot;
    bool debug;

    int jackVal;
    int fcVal;
    double mbVal;
    double d1Val;
    double d2Val;
    double g1Val;
    double g2Val;

    void debugMode();
    bool isReady();
};


#endif