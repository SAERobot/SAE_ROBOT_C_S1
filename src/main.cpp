/* 

    Projet SAE Robot
    goofyBot
    TEAM COOCHIE - IUT Nice Côte D'Azur 
    Licence MIT - 2023 

*/

#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>

// Programmes
#include <confettis.hpp>
#include <carre.hpp>
#include <suiveurLigne.hpp>

Thread threadDebug;
Robot goofyBot;

int main() {

    threadDebug.start(callback(&goofyBot, &Robot::debug));
    carre(goofyBot);

}