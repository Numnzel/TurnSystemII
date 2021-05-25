#include "UnitBuilder.h"

    std::map <std::string, Unit> UnitBuilder::memUnits;
    std::map <std::string, std::string> UnitBuilder::memUnitId;
    
    UnitBuilder::UnitBuilder () {}

    void UnitBuilder::initialize (std::string list) {

        std::ifstream i (list);
        nlohmann::json j;
        i >> j;

        // Fill unit register
        for (const auto& item : j.items())
            for (const auto& val : item.value().items()) {

                Unit tempUnit = Unit(val.value()["id"]);
                tempUnit.setName(val.value()["name"]);
                tempUnit.setHealth(val.value()["health"]);
                tempUnit.setSpeed(val.value()["speed"]);
                tempUnit.setDescription(val.value()["description"]);

                memUnits.insert(std::pair<std::string, Unit>(val.value()["id"], tempUnit));
                memUnitId.insert(std::pair<std::string, std::string>(val.value()["id"], val.value()["name"]));
            }
    }

    std::string UnitBuilder::print () {

        std::string str = "";
        std::map<std::string, Unit>::iterator it;
        for (it = memUnits.begin(); it != memUnits.end(); it++)
            str += it->second.getName() + ":"
                + std::to_string(it->second.getHealth()) + ":"
                + std::to_string(it->second.getSpeed()) + ":"
                + it->second.getDescription() + ":"
                + "\n";

        return str;
    }

    Unit* UnitBuilder::getUnit (std::string name) {

        std::string match = "";
        std::map<std::string, std::string>::iterator it;
        for (it = memUnitId.begin(); it != memUnitId.end(); it++)
            if (name == (*it).second) {
                match = (*it).first;
                break;
            }

        if (match == "")
            return NULL;

        return &(memUnits.find(match)->second);
    }

    bool UnitBuilder::checkUnit (std::string name) {

        std::map<std::string, std::string>::iterator it;
        for (it = memUnitId.begin(); it != memUnitId.end(); it++)
            if (name == (*it).second)
                return true;

        return false;
    }