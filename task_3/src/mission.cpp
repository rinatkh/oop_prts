#include "mission.h"

std::string Mission::get_coordinates() const {
    return std::string();
}

std::string Lift::get_coordinates() const {
    return Mission::get_coordinates();
}
