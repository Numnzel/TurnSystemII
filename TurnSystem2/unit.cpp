#include "unit.h"

    unit::unit (std::string name) {

        this->name = name;

        skillList.insert(skill("attack", 100));
        skillList.insert(skill("dodge", 100));
        skillList.insert(skill("guard", 100));
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

    std::string unit::getName() {
        return name;
    }

    std::set<skill> unit::getSkills() {
        return skillList;
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

    void unit::doTurn() {
        //turn = true;
    }

    void unit::endTurn() {
        //turn = false;
    }

    bool unit::checkTurn () {
        
        turntime += speed;

        turn = (turntime >= maxtime);

        if (turn)
            turntime -= maxtime;

        return turn;
    }
