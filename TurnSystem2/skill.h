#pragma once
#include <string>
#include <iostream>

class skill {
    
    public:
        std::string name = "undefined";
        short damage = 1;
        
    public:
        skill (std::string skname, short skdamage);
        short getDamage ();
        bool operator<(const skill& rhs) const;

    private:
        friend std::ostream& operator<<(std::ostream& os, const skill& lhs) noexcept;
};

std::ostream& operator<<(std::ostream& os, const skill& lhs) noexcept;