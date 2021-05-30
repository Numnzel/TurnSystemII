#include "unit.h"

    Unit::Unit (std::string id) {

        this->id = id;
    }

    void Unit::setCounter(unsigned int value) {
        maxtime = value;
    }

    void Unit::setName(std::string value) {
        name = value;
    }

    void Unit::setHealth(unsigned int value) {

        if (value > getMaxHealth())
            health = getMaxHealth();
        else if (value < 0)
            health = 0;
        else
            health = value;
    }

    void Unit::setMaxHealth(unsigned int value) {
        maxHealth = value;
    }

    void Unit::setSpeed(unsigned short value) {
        speed = value;
    }

    void Unit::setDescription(std::string data) {
        description = data;
    }

    std::string Unit::getName() {
        return name;
    }

    std::set<skill> Unit::getSkills() {
        return unitSkills;
    }

    unsigned int Unit::getHealth() {
        return health;
    }

    unsigned int Unit::getMaxHealth() {
        return maxHealth;
    }

    unsigned short Unit::getSpeed() {
        return speed;
    }

    std::string Unit::getDescription() {
        return description;
    }

    short Unit::getPos() {
        return turntime;
    }

    int Unit::damageUnit (int damage) {

        int healthSubs = health - damage;

        setHealth(healthSubs);

        return getHealth();
    }

    void Unit::addSkill (skill skill) {

        unitSkills.insert(skill);
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
