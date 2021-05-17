#include <set>
#include <string>
#include "skill.h"

class unit {

    std::string name = "undefined";
    short speed = 0;
    short maxtime = 0;
    short turntime = 0;
    short health = 0;
    std::set<skill> skillList;
    bool turn = false;

	public:
		unit (std::string name);
        void setCounter (int counter);
        void setSpeed (short sp);
        void setHealth (short sp);
        std::string getName();
        std::set<skill> getSkills();
        short getSpeed();
        short getHealth();
        short getPos();
        void doTurn ();
        void endTurn ();
        bool checkTurn ();
};