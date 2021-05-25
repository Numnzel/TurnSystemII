#pragma once
#include <string>
#include <iostream>

class skill {
    
    private:
        friend std::ostream& operator<< (std::ostream& os, const skill& lhs) noexcept;

    public:
        std::string name = "undefined";
        short damage = 1;

        skill(std::string skname, short skdamage);
        short getDamage();
        bool operator< (const skill& rhs) const;
        bool operator== (const std::string rhs) const;
};

std::ostream& operator<< (std::ostream& os, const skill& lhs) noexcept;