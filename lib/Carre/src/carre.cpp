#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>

// Programme carré

void carre(Robot& goofyBot) {
    int i = 0;
    int longueur = ihmSel(goofyBot);

       do {
        goofyBot.move(0.35,0.35);
        wait_us ((longueur / 45.5) * 1000000);
        goofyBot.move(0,0);
        wait_us(500000); 
        goofyBot.move(-0.75,0.75);
        wait_us(210000);
        i++;
       } while (i<4);

    goofyBot.move(0,0);
}