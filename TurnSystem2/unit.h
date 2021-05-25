#pragma once
#include <set>
#include <string>
#include "skill.h"

class Unit {

    private:
        std::string id;
        std::string name = "undefined";
        short health = 0;
        short speed = 0;
        std::string description = "undefined";
        short maxtime = 0;
        short turntime = 0;

        std::set<skill> unitSkills;
        bool turn = false;

	public:
		Unit (std::string id);
        void setCounter (int counter);
        void setName (std::string data);
        void setHealth (short data);
        void setSpeed (short data);
        void setDescription (std::string data);
        std::string getName ();
        std::set<skill> getSkills ();
        short getHealth ();
        short getSpeed ();
        std::string getDescription ();
        short getPos ();
        void addSkill (skill skill);
        void doTurn ();
        void endTurn ();
        bool checkTurn ();
};