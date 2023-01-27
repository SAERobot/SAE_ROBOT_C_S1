#include <mbed.h>
#include <robot.hpp>

void ihmBoot(Robot& goofyBot) {
    while(true) {
        if(goofyBot.IHM_Btn1.read() == 0) {
            goofyBot.IHM_Led1.write(1);
        }
        else {
            goofyBot.IHM_Led1.write(0);
        }
        if(goofyBot.IHM_Btn2.read() == 0) {
            goofyBot.IHM_Led2.write(1);
        }
        else {
            goofyBot.IHM_Led2.write(0);
        }
        if(goofyBot.IHM_Btn3.read() == 0) 
        {
            goofyBot.IHM_Led3.write(1);
        }
        else {
            goofyBot.IHM_Led3.write(0);
        }
        if(goofyBot.IHM_Btn4.read() == 0) {
            goofyBot.IHM_Led4.write(1);
        }
        else {
            goofyBot.IHM_Led4.write(0);
        }
    }
    return;
}

void ihm(Robot& goofyBot) {
    // Après démarrage de l'IHM, on attend que le programme soit sélectionné
    while(goofyBot.mode == WAITING_MODE ) {
        if(goofyBot.IHM_Btn1.read() == 0) {
            goofyBot.mode = CONFETTIS_MODE;
        }
        else if(goofyBot.IHM_Btn2.read() == 0) {
            goofyBot.mode = LINE_FOLLOWING_MODE ;
        }
        else if(goofyBot.IHM_Btn3.read() == 0) {
            goofyBot.mode = SQUARE_MODE ;
        }
        else if(goofyBot.IHM_Btn4.read() == 0) {
            goofyBot.mode = DEBUG_MODE ;
        }
    }

    // Une fois le programme sélectionné, on lance le programme
    switch(goofyBot.mode) {
        case CONFETTIS_MODE:
            //confettis(goofyBot);
            break;
        case LINE_FOLLOWING_MODE:
            // suiveurLigne(goofyBot);
            break;
        case SQUARE_MODE:
            // carre(goofyBot);
            break;
        case DEBUG_MODE:
            goofyBot.debugMode();
            break;
        default:
            break;
    }
}
