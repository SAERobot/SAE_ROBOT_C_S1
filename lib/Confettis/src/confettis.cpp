#include <mbed.h>
#include <robot.hpp>

// Programme confettis

void confettis(Robot& goofyBot) {
    int etat = 1;
    
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
                break;
            
            case 2:
                if(goofyBot.dIntVal >= 0.2 || goofyBot.dExtVal >= 0.2 || goofyBot.gIntVal >= 0.2 || goofyBot.gExtVal >= 0.2) {
                    goofyBot.move(50,50);
                } else {
                    etat = 3;
                }
                break;

            case 3:
                wait_us(300000);
                goofyBot.move(0,0);
                etat = 1;
                break;
        }
    }
}
