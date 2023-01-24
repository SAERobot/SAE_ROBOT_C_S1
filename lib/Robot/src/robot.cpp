#include "robot.hpp"

Robot::Robot() :
    jack(PTE20),
    finCourse(PTE21),
    mesureBatterie(A0),
    captLigneDroite1(A1),
    captLigneDroite2(A2),
    captLigneGauche1(A3),
    captLigneGauche2(A4)
{
    debug = false;
    boot = false;
}

void Robot::debugMode() {
    printf("Jack | FinCourse | MesureBatterie | Droite1 | Droite2 | Gauche1 | Gauche2\n");
    while (1) {
        jackVal = jack.read();
        fcVal = finCourse.read();
        mbVal = mesureBatterie.read();
        d1Val = captLigneDroite1.read();
        d2Val = captLigneDroite2.read();
        g1Val = captLigneGauche1.read();
        g2Val = captLigneGauche2.read();
        printf("%4d | %9d | %14.2f | %7.2f | %7.2f | %7.2f | %7.2f\n", 
            jackVal, 
            fcVal, 
            mbVal, 
            d1Val, 
            d2Val,
            g1Val,
            g2Val
        );
        thread_sleep_for(300);
    }
}