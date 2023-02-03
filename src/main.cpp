/* Projet SAE Robot
 * Robot Suiveur de ligne
 * TEAM COOCHIE - IUT Nice Côte D'Azur 
 * Licence MIT
 */

#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>

// Programmes
#include <confettis.hpp>
#include <carre.hpp>
// #include <suiveurLigne.hpp>

Thread threadDebug;
Robot goofyBot;

int main() {

    carre(goofyBot);

}