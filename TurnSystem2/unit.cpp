#include "unit.h"

    Unit::Unit (std::string id) {

        this->id = id;
    }

    void Unit::addSkill (skill skill) {

        unitSkills.insert(skill);
    }

    void Unit::setCounter (int counter) {
        maxtime = counter;
    }

    void Unit::setName (std::string data) {
        name = data;
    }

    void Unit::setHealth (short data) {
        health = data;
    }

    void Unit::setSpeed (short data) {
        speed = data;
    }

    void Unit::setDescription (std::string data) {
        description = data;
    }

    std::string Unit::getName () {
        return name;
    }

    std::set<skill> Unit::getSkills () {
        return unitSkills;
    }

    short Unit::getHealth () {
        return health;
    }

    short Unit::getSpeed () {
        return speed;
    }

    std::string Unit::getDescription () {
        return description;
    }

    short Unit::getPos () {
        return turntime;
    }

    void Unit::doTurn () {
        //turn = true;
    }

    void Unit::endTurn () {
        //turn = false;
    }

    bool Unit::checkTurn () {
        
        turntime += speed;

        turn = (turntime >= maxtime);

        if (turn)
            turntime -= maxtime;

        return turn;
    }
