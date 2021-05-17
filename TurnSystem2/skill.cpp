#include "skill.h"

skill::skill(std::string skname, short skdamage) {

    name = skname;
    damage = abs(skdamage);
}

short skill::getDamage() {

    return damage;
}

bool skill::operator<(const skill& rhs) const {

    if (this->name < rhs.name)
        return true;

    return false;
}

std::ostream& operator<<(std::ostream& os, const skill& lhs) noexcept {
    
    os << lhs.name;
    return os;
}
