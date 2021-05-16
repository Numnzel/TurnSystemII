#include "unit.h"

    unit::unit () {
        //skills = new skillList();
        //cout << "Created unit";
        skillList.insert(skill("attack", 100));   //.add(new skill("attack", 100));
        skillList.insert(skill("attack2", 100));
        skillList.insert(skill("attack3", 100));
    }

    void unit::setCounter (int counter) {
        maxtime = counter;
    }

    void unit::setSpeed (short sp) {
        speed = sp;
    }

    void unit::setHealth (short sp) {
        health = sp;
    }

    void unit::doTurn () {
        //turn = true;
    }

    void unit::endTurn () {
        //turn = false;
    }

    short unit::getSpeed () {
        return speed;
    }

    short unit::getHealth () {
        return health;
    }

    short unit::getPos () {
        return turntime;
    }

    /*skill unit::getSkill(skill s) {
        return skillList.find(s);
    }*/

    std::set<skill> unit::getSkills () {
        return skillList;
    }

    bool unit::checkTurn () {
        
        turntime += speed;

        turn = (turntime >= maxtime);

        if (turn)
            turntime -= maxtime;

        return turn;
    }
