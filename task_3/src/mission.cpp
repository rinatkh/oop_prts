#include "mission.h"

std::string Mission::get_coordinates() const {
    std::stringstream str;
    str << "x:\t" << x << "\ty:\t" << y << "\tdepth:\t" << depth;
    return str.str();
}

std::string Lift::get_coordinates() const {
    std::stringstream str;
    str << "depth:\t" << depth;
    return str.str();
}

bool Lift::set() {
    if (depth <= max_deep && depth >= min_deep) {
        return true;
    }
    return false;
}

std::string Lift::get_mission() {
    std::stringstream str;
    str << "Lift\n"
        << "\tTo:          " << get_coordinates() << "\n"
        << "\tDepth mode:  "
        << (mode_setting == lift_mode::SPIRAL ? "SPIRAL lift" : "VERTICAL lift")
        << "\n"
        << "\tSensor:      "
        << (sensor == sensor_mode::EHOLOT ? "EHOLOT SENSOR" : "SENSOR OT THE DEPTH lift")
        << "\n";
    return str.str();
}

Lift::Lift(double depth, int mode, int sensor) {
    auto m = static_cast<lift_mode>(mode);
    auto s = static_cast<sensor_mode>(sensor);

    depth = depth;
    mode_setting = m;
    sensor = s;
}

std::string Dive::get_coordinates() const {
    std::stringstream str;
    str << "depth:\t" << depth;
    return str.str();
}

bool Dive::set() {
    if (depth <= max_deep && depth >= min_deep) {
        return true;
    }
    return false;
}

std::string Dive::get_mission() {
    std::stringstream str;
    str << "Dive\n"
        << "\tTo:          " << get_coordinates() << "\n"
        << "\tDepth mode:  "
        << (mode_setting == dive_mode::SPIRAL ? "SPIRAL lift" : "VERTICAL lift")
        << "\n"
        << "\tSensor:      "
        << (sensor == sensor_mode::EHOLOT ? "EHOLOT SENSOR" : "SENSOR OT THE DEPTH")
        << "\n";
    return str.str();
}

Dive::Dive(double depth, int mode, int sensor) {
    auto m = static_cast<dive_mode>(mode);
    auto s = static_cast<sensor_mode>(sensor);

    depth = depth;
    mode_setting = m;
    sensor = s;
}

std::string Move::get_coordinates() const {
    std::stringstream str;
    str << "x:\t" << x << "\ty:\t" << y;
    return str.str();
}

bool Move::set() {
    if ((x < max_x && x > min_x) && (y < max_y && y > min_y)) {
        return true;
    }
    return false;
}

std::string Move::get_mission() {
    std::stringstream str;
    str << "Move\n"
        << "\tTo:          " << get_coordinates() << "\n"
        << "\tAccuracy:    " << accuracy << "\n"
        << "\n"
        << "\tMove mode:   " << (mode_setting == move_mode::PROCCED ? "stay at the target point"
                                                                    : "keep moving among the line")
        << "\n"
        << "\tMotion mode: " << (motion_node == motion::LINE ? "motion by line"
                                                               : "motion in dot")
        << "\n";
    return str.str();
}

Move::Move(double _x, double _y, double _accuracy, int mode, int _motion_node) {
    x = _x;
    y = _y;
    accuracy = _accuracy;
    auto m = static_cast<move_mode> (mode);
    mode_setting = m;
    auto n = static_cast<motion> (_motion_node);
    motion_node = n;
}

bool Return::set() {
    return true;
}

std::string Return::get_mission() {
    std::stringstream ss;
    ss << "Return\n"
       << "\tTo:   " << get_coordinates() << "\n";
    return ss.str();
}

std::string Return::get_coordinates() const {
    std::stringstream str;
    str << "x:\t" << x << "\ty:\t" << y << "\tdepth:\t" << depth;
    return str.str();
}

Return::Return() {
    x = 0.0;
    y = 0.0;
    depth = 0.0;
}
