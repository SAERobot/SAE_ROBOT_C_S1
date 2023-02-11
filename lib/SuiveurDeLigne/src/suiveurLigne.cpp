#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>
#include <math.h>

// Programme suiveur de ligne

void suiveurLigne(Robot& goofyBot) {
    int etat = 0;
    float e, k, coeffG, coeffD, coeffExt;
    k = 5;

    while(true) {
        goofyBot.jackVal = goofyBot.jack.read();
        goofyBot.fcVal = goofyBot.finCourse.read();
        goofyBot.dIntVal = goofyBot.captLigneDroiteInt.read()*3.3;
        goofyBot.dExtVal = goofyBot.captLigneDroiteExt.read()*3.3;
        goofyBot.gIntVal = goofyBot.captLigneGaucheInt.read()*3.3;
        goofyBot.gExtVal = goofyBot.captLigneGaucheExt.read()*3.3;    

        e = (goofyBot.gIntVal - goofyBot.dIntVal);

        if(goofyBot.fcVal == 0) {
            etat = 69;
        }

        switch(etat) {
            case 0:
                if(goofyBot.jackVal == 1) {
                    etat = 1; //suivi
                } 
                break;
            
            case 1:
                if(e <= -0.05 || e >= 0.05) {
                    etat = 2;
                }
                break;

            case 2:
                if(goofyBot.dExtVal < 1.0 || goofyBot.gExtVal < 1.0) { //case extreme
                    etat = 3;
                }
                if (e <= 0.05 && e >= -0.05) {
                    etat = 1;
                }
                break;

            case 3: 
                if (e <= 0.02 && e >= -0.02) {
                    etat = 1;
                }
                if(e <= -0.05 && e >= 0.05) {
                    etat = 2;
                }
                break;
        }

        switch(etat) {
            case 0:
                if(e <= 0.01 && e >= -0.01) {
                    goofyBot.IHM_Led3.write(1);    
                } else {
                    goofyBot.IHM_Led3.write(0);
                }
                goofyBot.move(0,0);
                break;

            case 1:
                goofyBot.move(35,35);
                break;

            case 2:
                coeffG = (30 + (k*e));
                coeffD = (30 - (k*e));
                goofyBot.move(coeffG,coeffD);
                break;

            case 3:
                coeffG = (30 + (k*e));
                coeffD = (30 - (k*e));
                if(goofyBot.dExtVal < 1.0) {
                    coeffG *= 1.25;
                }
                if(goofyBot.gExtVal < 1.0) {
                    coeffD *= 1.25;
                }
                goofyBot.move(coeffG,coeffD);
                break;

            case 69: 
                goofyBot.move(0,0);
                break;
        }
    }
}