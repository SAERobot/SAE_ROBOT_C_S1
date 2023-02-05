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

// Deprecated function a changer
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

// Nouvelle fonction de déplacement

void Robot::move(float pwmGauche, float pwmDroit) {
    moteurDroit.period(T);
    moteurGauche.period(T);

    if(pwmDroit >= -100 && pwmDroit < 0) { // Si le pwm est négatif, on inverse le sens du moteur et on prend la valeur absolue du pwm
        moteurDroitSens = 0;
        pwmDroit = -pwmDroit;
        pwmDroit /= 100; // On divise par 100 pour avoir un pwm entre 0 et 1
    } else if(pwmDroit > 0 && pwmDroit <= 100) { // Si le pwm est positif, on met le sens du moteur à 1 (avancer)
        moteurDroitSens = 1;
        pwmDroit /= 100;
    } else {
        pwmDroit = 1; // Sinon on met le pwm à 0
    }

    if(pwmGauche >= -100 && pwmGauche < 0) { 
        moteurGaucheSens = 0;
        pwmGauche = -pwmGauche;
        pwmGauche /= 100;
    } else if(pwmGauche > 0 && pwmGauche <= 100) {
        moteurGaucheSens = 1;
        pwmGauche /= 100;
    } else {
        pwmGauche = 1;
    }

    moteurDroit.pulsewidth(T * pwmDroit);
    moteurGauche.pulsewidth(T * pwmGauche);
}