#include <mbed.h>
#include <robot.hpp>

#include <confettis.hpp>

void ihmDebug(Robot& goofyBot) {
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

void ihmBoot(Robot& goofyBot) {
    // Après démarrage de l'IHM, on attend que le programme soit sélectionné
    while(1) {
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
                goofyBot.IHM_Led1.write(0);
                confettis(goofyBot);
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
                goofyBot.IHM_Led1.write(1);
                goofyBot.IHM_Led2.write(1);
                goofyBot.IHM_Led3.write(1);
                goofyBot.IHM_Led4.write(1);
                break;
        }
    }
}

int ihmSel(Robot& goofyBot) {
    // Taille en CM du carré (entre 60 et 200)
    int res = 0;
    while(goofyBot.IHM_Btn4.read() == 0) {
        if (goofyBot.IHM_Btn1.read() == 1) {
            // Ajout dizaines
            res += 10;
            wait_us(1000000);
        }
        else if (goofyBot.IHM_Btn2.read() == 1) {
            // Ajout centaines
            res += 100;
            wait_us(1000000);

        }
        else if (goofyBot.IHM_Btn3.read() == 1) {
            // Reset
            res = 0;
        }
        
    }
    if(res > 200 || res < 60) {
        res = 0;
        goofyBot.IHM_Led1.write(0);
        wait_us(500000);
        goofyBot.IHM_Led1.write(1);
        wait_us(500000);
    }

    for(int i = 0; i < 5; i++) {
        goofyBot.IHM_Led1.write(0);
        wait_us(500000);
        goofyBot.IHM_Led1.write(1);
        wait_us(500000);
    }
    return res;
}