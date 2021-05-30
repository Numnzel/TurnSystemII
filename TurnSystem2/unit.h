#pragma once
#include <set>
#include <string>
#include "skill.h"

class Unit {

    private:
        std::string id;
        std::string name = "undefined";
        unsigned int maxHealth = 0;
        unsigned int health = 0;
        unsigned short status = 0;
        unsigned short speed = 0;
        std::string description = "undefined";
        unsigned short maxtime = 0;
        short turntime = 0;

        std::set<skill> unitSkills;
        bool turn = false;

	public:
		Unit (std::string id);
        void setCounter (unsigned int counter);
        void setName (std::string value);
        void setHealth (unsigned int value);
        void setMaxHealth (unsigned int value);
        void setSpeed (unsigned short value);
        void setDescription (std::string data);
        std::string getName ();
        std::set<skill> getSkills ();
        unsigned int getHealth ();
        unsigned int getMaxHealth ();
        unsigned short getSpeed ();
        std::string getDescription ();
        short getPos ();
        int damageUnit (int damage);
        void addSkill (skill skill);
        void doTurn ();
        void endTurn ();
        bool checkTurn ();
};