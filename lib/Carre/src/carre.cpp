#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>

// Programme carré

void carre(Robot& goofyBot) {
    int etat = 0;
    int i=0;
    int longueur = ihmSel(goofyBot);
    printf("Longueur : %d", longueur);

       do {
        goofyBot.sens(1,1);
        goofyBot.avancer(0.650,0.650);
        wait_us ((longueur / 45.5) * 1000000) ;
        goofyBot.sens(1, 1);
        goofyBot.avancer(1,1);
        wait_us(500000);
        goofyBot.sens(0,1);
        goofyBot.avancer(0.75,0.25);
        wait_us(210000);
        i++;
       } while (i<4);



    goofyBot.sens(1,1);
    goofyBot.avancer(1,1);

                
}