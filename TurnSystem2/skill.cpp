#include "skill.h"

bool skill::operator<(const skill& rhs) const
{
    if (this->damage < rhs.damage)
        return true;
    else
        return false;
}

skill::skill(std::string skname, short skdamage) {

    //cout << "Created skill";
    name = skname;
    damage = skdamage;
}


/*
bool operator()(const skill& lhs, const skill& rhs) const noexcept
{
    return lhs.name < rhs.name; // comparision logic
}*/

std::string skill::getName() {
    return name;
}

short skill::getDamage() {
    return damage;
}