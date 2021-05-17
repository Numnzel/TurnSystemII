#include <string>
#include <iostream>
#include <limits>
#include <math.h>
#include <list>
#include <vector>

#include "skill.h"
#include "unit.h"

#define TIMECOUNTER 255

using namespace std;

short setUnitsAmount() {

    short n;
    std::cout << "Enter the number of units:\n";
    std::cin >> n;

    while (!std::cin.good() || n <= 0 || n > 10) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter the number of units: (Warning: Only integers between 1 and 10 allowed)\n";
        std::cin >> n;
    }

    return n;
}

void setupUnits(unit* units, short n) {

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

bool gameLogic(short time, unit* units, short n) {

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

            std::set<skill> skills = units[i].getSkills();

            std::set<skill>::iterator it;
            for (it = skills.begin(); it != skills.end(); it++) {
                std::cout << *it << " ";
            }

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

    std::cout << "-- Initiating game --\n";

    // Create units
    
    short unit_n = setUnitsAmount();

    std::vector<unit> units;
    units.reserve(unit_n);

    for (short i = 0; i < unit_n; i++) {
        
        std::string n;
        std::cout << "Enter the name of unit " << i << ": ";
        std::cin >> n;

        units.push_back(unit(n));
    }
    
    // Setup units stats
    setupUnits(units.data(), unit_n);

    // Start game
    short time = 0;

    // Setup units counters
    for (short i = 0; i < unit_n; i++)
        units[i].setCounter(TIMECOUNTER);

    std::cout << "-- Starting combat --\n";
    std::cout << "INFO: Press ENTER to end the turn.\n";
    std::cin.ignore();

    while (true) {

        bool state;

        state = gameLogic(time, units.data(), unit_n);

        if (state)
            break;

        if (++time > TIMECOUNTER)
            time = 0;
    }

    std::cout << "-- Combat ended --\n";

    //delete units;

    goto Start;
}

