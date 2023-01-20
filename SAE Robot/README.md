# SAE Robot : Programmation

Ce programme permet de contrôler un robot suiveur de ligne en utilisant le microcontrôleur mbed FRDM-KL25Z.

| Caractéristique | Valeur |
| Microcontrôleur | MKL25Z128VLK4 |
| Fréquence d'horloge | 48 MHz |
| Flash de mémoire | 128 KB |
| RAM | 16 KB |
| Interfaces de communication | USB, I2C, SPI, UART |
| Tension d'alimentation | 3.3 V |
| Température de fonctionnement | -40°C à 85°C |
| Dimensions (en mm) | 31.75 x 25.4 |

## Installation
1. Téléchargez le binary à partir de ce dépôt [Releases](https://github.com/SAEs-Coochie/SAE_ROBOT_C/releases/latest)
2. Branchez les cartes de capteurs, de commande, de IHM et de quadrants en pont en H sur le microcontrôleur
3. Connectez le microcontrôleur frdm-kl25z à l'ordinateur à l'aide d'un câble USB
4. Téléversez le code sur le microcontrôleur
5. Allumez le robot et vérifiez que tout fonctionne correctement

## Building and running

### Mbed CLI 2
Starting with version 6.5, Mbed OS uses Mbed CLI 2. It uses Ninja as a build system, and CMake to generate the build environment and manage the build process in a compiler-independent manner. If you are working with Mbed OS version prior to 6.5 then check the section [Mbed CLI 1](#mbed-cli-1).
1. [Install Mbed CLI 2](https://os.mbed.com/docs/mbed-os/latest/build-tools/install-or-upgrade.html).
2. Change the current directory to where the project was imported.

### Mbed CLI 1
1. [Install Mbed CLI 1](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).
2. Change the current directory to where the project was imported.

3. Connect a USB cable between the USB port on the board and the host computer.
4. Run the following command to build the example project and program the microcontroller flash memory:

    * Mbed CLI 2

    ```bash
    $ mbed-tools compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

    * Mbed CLI 1

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

Your PC may take a few minutes to compile your code.

The binary is located at:
* **Mbed CLI 2** - `./cmake_build/<TARGET>/develop/<TOOLCHAIN>/mbed-os-example-blinky.bin`
* **Mbed CLI 1** - `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin`

## Note
- Assurez-vous que toutes les connexions entre les cartes et le microcontrôleur sont correctes avant de téléverser le code et de démarrer le robot.
- Vérifiez que les paramètres de sensibilité et de vitesse sont correctement réglés pour votre surface de ligne.
- Ce code est fourni "tel quel" sans garantie expresse ou implicite. L'utilisateur assume tous les risques liés à son utilisation.

## Copyright (c) 2023 - Team Coochie