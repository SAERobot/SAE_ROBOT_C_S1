/* Projet SAE Robot
 * Robot Suiveur de ligne
 * TEAM COOCHIE - IUT Nice Côte D'Azur 
 * Licence MIT
 */

using namespace std;

#include <mbed.h>
#include <robot.hpp>
#include "ihm.cpp"
#include "cmd_moteurs.cpp"
#include "cmd_ligne.cpp"

Thread threadDebug;
Robot goofyBot;

void debugMode() {
  goofyBot.debugMode();
}

int main() {
  // Mode debug du robot
  goofyBot.debug = true;
  
  if(goofyBot.debug == true) {
    threadDebug.start(debugMode);
  }

  // goofyBot.start();
}