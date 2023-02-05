#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>
#include <math.h>

// Programme suiveur de ligne

void suiveurLigne(Robot& goofyBot) {
    // Le robot suit la ligne blanche jusqu'à ce qu'il rencontre un obstacle
    int etat = 1;

    Thread *arretFDCThread = new Thread();
    arretFDCThread->start(callback(arretFDC, &goofyBot));

    while (1) {
        goofyBot.jackVal = goofyBot.jack.read();
        goofyBot.dIntVal = goofyBot.captLigneDroiteInt.read() * 3.3;
        goofyBot.dExtVal = goofyBot.captLigneDroiteExt.read() * 3.3;
        goofyBot.gIntVal = goofyBot.captLigneGaucheInt.read() * 3.3;
        goofyBot.gExtVal = goofyBot.captLigneGaucheExt.read() * 3.3;

        switch(etat) {
            case 1:
                if (goofyBot.jackVal == 1) {
                    etat = 2;
                }
                goofyBot.IHM_Led2.write(1);
                goofyBot.IHM_Led3.write(1);
                break;
            
            case 2: // Cas où le robot est sur la ligne
                if(abs(goofyBot.dIntVal - goofyBot.gIntVal) <= 0.05) {
                    goofyBot.move(70,70);
                } else {
                    etat = 3;
                }
                break;

            case 3: // Cas de gestion de ligne
                if(abs(goofyBot.dIntVal - goofyBot.gIntVal) >= 0.05 && goofyBot.dIntVal > goofyBot.gIntVal) { // Si la ligne est à droite
                    while(abs(goofyBot.dIntVal - goofyBot.gIntVal) > 0.05) {
                        goofyBot.move(70, 30);
                    }
                } else if(abs(goofyBot.dIntVal - goofyBot.gIntVal) >= 0.05 && goofyBot.dIntVal < goofyBot.gIntVal) { // Si la ligne est à gauche
                    while(abs(goofyBot.dIntVal - goofyBot.gIntVal) > 0.05) {
                        goofyBot.move(30, 70);
                    }
                } else { // Cas d'urgence
                    etat = 4;
                }
                break;

            case 4: // Cas d'urgence
                while(goofyBot.dExtVal >= 1.5 || goofyBot.gExtVal >= 1.5) {
                    goofyBot.move(10,10);
                }
                while(abs(goofyBot.dIntVal - goofyBot.gIntVal) <= 0.05) {
                    if(goofyBot.dExtVal <= 1.5) {
                        goofyBot.move(0, 70);
                    } else if(goofyBot.gExtVal <= 1.5) {
                        goofyBot.move(70, 0);
                    } 
                }
                etat = 3;
                break;
        }
    }
}

void arretFDC(Robot *goofyBot) {
    while(1) {
        goofyBot.fcVal = goofyBot.finCourse.read();
        if(goofyBot.fcVal == 0) {
            wait_us(50000);
            goofyBot.move(0,0);
        }
    }
}