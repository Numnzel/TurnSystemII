#include <string>
#include <iostream>
#include <limits>
#include <math.h>
#include <list>

#include "skill.h"
#include "unit.h"

#define TIMECOUNTER 255

using namespace std;

short setunitsamount() {

    short n;
    cout << "Enter the number of units:\n";
    cin >> n;

    while (!std::cin.good() || n <= 0 || n > 10) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter the number of units: (Warning: Only integers between 1 and 10 allowed)\n";
        std::cin >> n;
    }

    return n;
}

void setupunits(unit* units, short n) {

    for (short i = 0; i < n; i++) {

        short sp;

        std::cout << "Enter unit " << i << " speed:\n";
        std::cin >> sp;

        while (!std::cin.good() || sp <= 0 || sp > 255) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter unit " << i << " speed: (Warning: Only integers between 1 and 255 allowed)\n";
            std::cin >> sp;
        }

        units[i].setSpeed(sp);

        std::cout << "Enter unit " << i << " health:\n";
        std::cin >> sp;

        while (!std::cin.good() || sp <= 0 || sp > 255) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter unit " << i << " health: (Warning: Only integers between 1 and 255 allowed)\n";
            std::cin >> sp;
        }

        units[i].setHealth(sp);
    }
}

bool gamelogic(short time, unit* units, short n) {

    short gtime = time + 1;
    std::string input;

    // For each unit...
    for (short i = 0; i < n; i++) {

        // Check turn order
        if (units[i].checkTurn()) {

            std::cout << "(Time: " << gtime << ") Unit " << i << " turn\n";
            //cout << "\nPress enter to end turn";
            //cin >> input;

            std::cout << "Skills: ";

            //std::set<skill> ski = units[i].getSkills();
            //for (short s = 0; s < units[i].getSkillsN(); s++) {
            //    skillList = skillList + units[i].getSkill(s).getName() + "\n";
            //}

            //cout << skillList;

            std::cin.ignore();

            if (input == "\n")
                return true;
        }
    }

    return false;
}

int main() {

    std::cout << "Welcome to Numnzel's turn-based system.\n";

Start:

    // Create units
    short unit_n = setunitsamount();
    unit* units = new unit[unit_n];

    // Setup units stats
    setupunits(units, unit_n);

    // Start game
    short time = 0;

    // Setup units counters
    for (short i = 0; i < unit_n; i++)
        units[i].setCounter(TIMECOUNTER);

    std::cout << "-- Starting game --\n";
    std::cout << "INFO: Press ENTER to end the turn.\n";
    std::cin.ignore();

    while (true) {

        bool state;

        state = gamelogic(time, units, unit_n);

        if (state)
            break;

        if (++time > TIMECOUNTER)
            time = 0;
    }

    //delete units;

    goto Start;
}

