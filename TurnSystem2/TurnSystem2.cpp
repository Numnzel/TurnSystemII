#include <nlohmann/json.hpp>
#include <fstream>

#include <string>
#include <iostream>
#include <limits>
#include <math.h>

#include <list>
#include <vector>
#include <map>

#include "skill.h"
#include "unit.h"
#include "UnitBuilder.h"

#define TIMECOUNTER 255

short setUnitsAmount () {

    short n;
    std::cout << "Enter the number of units: ";
    std::cin >> n;

    while (!std::cin.good() || n <= 0 || n > 10) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter the number of units: (Warning: Only integers between 1 and 10 allowed)\n";
        std::cin >> n;
    }

    return n;
}

bool combatLogic (short time, Unit* units, short n) {

    short gtime = time + 1;
    std::string input;

    // For each unit...
    for (short i = 0; i < n; i++) {

        // Check turn order
        if (units[i].checkTurn()) {

            std::string unitName = units[i].getName();

            std::cout << "(Time: " << gtime << ") Unit " << unitName << " turn. Use a skill: ";

            // Get and print available skills
            std::set<skill> skills = units[i].getSkills();

            std::set<skill>::iterator it;
            for (it = skills.begin(); it != skills.end(); it++)
                std::cout << *it << " ";

            // Wait for player to write a skill
            bool skillMatches = false;
            std::string use;

            do {
                std::cin >> use;

                // Search the skill and assign it if exists
                for (it = skills.begin(); it != skills.end(); it++)
                    if (use == (*it).name) {
                        skillMatches = true;
                        break;
                    }
                
            } while (!skillMatches);

            std::cout << unitName << " used the skill " << use << "\n";

            std::cin.ignore();

            if (input == "\n")
                return true;
        }
    }

    return false;
}

void gameLogic (std::map <std::string, skill> memSkills) {

    std::cout << "----- Initiating combat -----\n";

    // Get unit amounts
    short unit_n = setUnitsAmount();

    // Assign unit types
    std::vector<Unit> units;
    units.reserve(unit_n);

    for (short i = 0; i < unit_n; i++) {

        std::string name;
        bool unitMatches = false;

        do {
            std::cout << "Select the unit type for unit " << i << ":\n";
            std::cout << UnitBuilder::print() << "\n";
            std::cin >> name;

            unitMatches = UnitBuilder::checkUnit(name);

        } while (!unitMatches);

        Unit k = *UnitBuilder::getUnit(name);

        k.addSkill(memSkills.find("idattack")->second);
        k.addSkill(memSkills.find("idguard")->second);
        k.addSkill(memSkills.find("iddodge")->second);

        units.push_back(k);
    }

    // Start game
    short time = 0;

    // Setup units counters
    for (short i = 0; i < unit_n; i++)
        units[i].setCounter(TIMECOUNTER);

    std::cout << "----- Starting combat -----\n";
    std::cout << "INFO: Press ENTER to end the turn.\n";
    std::cin.ignore();

    while (true) {

        bool state;

        state = combatLogic(time, units.data(), unit_n);

        if (state)
            break;

        if (++time > TIMECOUNTER)
            time = 0;
    }

    std::cout << "----- Combat ended -----\n";

    //delete units;
}

int main () {

    std::cout << "Welcome to Numnzel's turn-based system.\n";
    std::cout << "----- Initiating game -----\n";

    // Create skill register
    std::map <std::string, skill> memSkills;

    // Store skill list in register
    std::ifstream i("skillList.json");
    nlohmann::json j;
    i >> j;

    // Fill skill register
    for (const auto& item : j.items())
        for (const auto& val : item.value().items())
            memSkills.insert(std::pair<std::string, skill>(val.value()["id"], skill(val.value()["name"], val.value()["damage"])));

    // Print skill list from register (debugging)
    /*
    std::map<std::string, skill>::iterator it;
    for (it = memSkills.begin(); it != memSkills.end(); it++)
        std::cout << ':' << it->second.name << std::endl;
    */
    
    // Create unit register
    UnitBuilder::initialize("unitList.json");
    
    // Print unit register (debugging)
    //std::cout << UnitBuilder::print();

    while (true) {

        gameLogic (memSkills);
    }
}

