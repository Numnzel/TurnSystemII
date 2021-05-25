#pragma once
#include <nlohmann/json.hpp>
#include <fstream>

#include <string>

#include "unit.h"

class UnitBuilder {

    private:
        static std::map <std::string, Unit> memUnits;
        static std::map <std::string, std::string> memUnitId;

        UnitBuilder();
    public:
        static void initialize (std::string list);
        static Unit* getUnit (std::string name);
        static bool checkUnit (std::string name);
        static std::string print ();
};