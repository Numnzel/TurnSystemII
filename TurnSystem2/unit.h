#include <set>
#include "skill.h"

class unit {

    short speed = 0;
    short maxtime = 0;
    short turntime = 0;
    short health = 0;
    std::set<skill> skillList;
    bool turn = false;

	public:
		unit ();
        void setCounter (int counter);
        void setSpeed (short sp);
        void setHealth (short sp);
        void doTurn ();
        void endTurn ();
        short getSpeed ();
        short getHealth ();
        short getPos ();
        //skill getSkill (skill s);
        std::set<skill> getSkills();
        bool checkTurn ();
};