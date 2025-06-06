#include <robot.hpp>

#define T 0.001

// Constructeur
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
    // Initialisation des moteurs
    moteurDroitSens = 1;
    moteurGaucheSens = 1;
}

void Robot::debugMode() {
    // Debug mode - Affichage des valeurs des capteurs
    float battery = 0.0;
    printf("Jack | FinCourse | MesureBatterie | DroiteE | DroiteI | GaucheI | GaucheE | Epsilon \n\r");
    while (1) {
        jackVal = jack.read();
        fcVal = finCourse.read();
        mbVal = mesureBatterie.read();
        battery = (mbVal*12*((1200.0+4700.0)/1200.0)+0.6);
        dIntVal = captLigneDroiteInt.read();
        dExtVal = captLigneDroiteExt.read();
        gIntVal = captLigneGaucheInt.read();
        gExtVal = captLigneGaucheExt.read();
        printf("%4d | %9d | %14.2lf | %7.2lf | %7.2lf | %7.2lf | %7.2lf | %7.2lf \n\r", 
            jackVal, 
            fcVal, 
            battery, 
            dExtVal * 3.3, 
            dIntVal * 3.3,
            gIntVal * 3.3,
            gExtVal * 3.3,
            (dIntVal - gIntVal)
        );
    }
}

void Robot::move(float pwmGauche, float pwmDroit) {
    // On définit la période des moteurs
    moteurDroit.period(T);
    moteurGauche.period(T);

    if(pwmGauche >= -100.0 && pwmGauche < 0) {
        moteurGaucheSens = 0; // Sens arrière
        pwmGauche = pwmGauche * -1.0;
        pwmGauche = pwmGauche / 100.0; // On divise par 100 pour avoir un pwm entre 0 et 1
    } else if (pwmGauche <= 100 && pwmGauche > 0) {
        moteurGaucheSens = 1; // Sens avant
        pwmGauche -= 100.0;
        pwmGauche = pwmGauche * -1.0;
        pwmGauche = pwmGauche / 100.0;
    } else if (pwmGauche == 0) {
        moteurGaucheSens = 1;
        pwmGauche = 1; // Stop
    }

    if(pwmDroit >= -100.0 && pwmDroit < 0) {
        moteurDroitSens = 0; // Sens arrière
        pwmDroit = pwmDroit * -1.0; // On inverse le signe du pwm
        pwmDroit = pwmDroit / 100.0; // On divise par 100 pour avoir un pwm entre 0 et 1
        //printf("%f", pwmDroit);
    } else if (pwmDroit <= 100 && pwmDroit > 0) {
        moteurDroitSens = 1; // Sens avant
        pwmDroit = pwmDroit - 100.0; 
        pwmDroit = pwmDroit * -1.0;
        pwmDroit = pwmDroit / 100.0; // On divise par 100 pour avoir un pwm entre 0 et 1
    } else if (pwmDroit == 0) {
        moteurDroitSens = 1;
        pwmDroit = 1; // Stop
    }

    // On applique le pwm aux moteurs
    moteurDroit.pulsewidth(T * pwmDroit);
    moteurGauche.pulsewidth(T * pwmGauche);
}  