#include <robot.hpp>

#define T 0.001

Robot::Robot() :
    jack(PTE20),
    finCourse(PTE21),
    mesureBatterie(A0),
    captLigneDroiteInt(A1),
    captLigneDroiteExt(A2),
    captLigneGaucheInt(A4),
    captLigneGaucheExt(A3),

    IHM_Led1(D15),
    IHM_Led2(D14),
    IHM_Led3(D13),
    IHM_Led4(D12),
    IHM_Btn1(D4),
    IHM_Btn2(D5),
    IHM_Btn3(A5),
    IHM_Btn4(PTE30),

    moteurDroit(D6),
    moteurGauche(D8),
    moteurDroitSens(D7),
    moteurGaucheSens(D9)
{
    mode = WAITING_MODE;
    boot = false;
}

void Robot::debugMode() {
    printf("Jack | FinCourse | MesureBatterie | DroiteE | DroiteI | GaucheI | GaucheE \n\r");
    while (1) {
        jackVal = jack.read();
        fcVal = finCourse.read();
        mbVal = mesureBatterie.read();
        dIntVal = captLigneDroiteInt.read();
        dExtVal = captLigneDroiteExt.read();
        gIntVal = captLigneGaucheInt.read();
        gExtVal = captLigneGaucheExt.read();
        printf("%4d | %9d | %14.2lf | %7.2lf | %7.2lf | %7.2lf | %7.2lf \n\r", 
            jackVal, 
            fcVal, 
            mbVal * 12, 
            dExtVal * 3.3, 
            dIntVal * 3.3,
            gIntVal * 3.3,
            gExtVal * 3.3
        );
        thread_sleep_for(50);
    }
}

void Robot::avancer(float pwmGauche, float pwmDroit) {
    moteurDroit.period(T);
    moteurGauche.period(T);
    moteurDroit.pulsewidth(T * pwmDroit);
    moteurGauche.pulsewidth(T * pwmGauche);
}

void Robot::sens(int sensGauche, int sensDroit) {
    moteurGaucheSens = sensGauche;
    moteurDroitSens = sensDroit;
}