/* Projet SAE Robot
 * Robot Suiveur de ligne
 * TEAM COOCHIE - IUT Nice Côte D'Azur 
 * Licence MIT
 */

using namespace std;

#include <mbed.h>
#include <robot.hpp>
#include <ihm.hpp>

// Programmes
#include <confettis.hpp>
// #include <carre.hpp>
// #include <suiveurLigne.hpp>

Thread threadDebug;
Robot goofyBot;

void debugMode() {
  goofyBot.debugMode();
}

int main() {
  // Mode debug du robot
  goofyBot.mode = DEBUG_MODE;
  
  if(goofyBot.mode == DEBUG_MODE) {
    threadDebug.start(debugMode);
  }

  ihmBoot(goofyBot);

  // goofyBot.start();
}