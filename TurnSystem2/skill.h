#pragma once
#include <string>

class skill {
    
    private:
        std::string name = "aaa";
        short damage = 1;
        
    public:
        bool operator<(const skill& rhs) const;
        skill (std::string skname, short skdamage);
        std::string getName ();
        short getDamage ();
};