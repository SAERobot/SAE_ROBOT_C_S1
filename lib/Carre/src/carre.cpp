#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>

// Programme carré

void carre(Robot& goofyBot) {
    int i = 0;
    int longueur = ihmSel(goofyBot);

    for(int i = 0; i < 4; i++) {
        goofyBot.move(35,35);
        wait_us ((longueur / 45.5) * 1000000);
        goofyBot.move(0,0);
        wait_us(500000); 
        goofyBot.move(-75,75);
    }

    goofyBot.move(0,0);
}