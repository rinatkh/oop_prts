#pragma once

#include "mission.h"
#include "operation.h"

#include <memory>

enum MISSIONS {
    ADD_MISSION_LIFT = 1,
    ADD_MISSION_DIVE = 2,
    ADD_MISSION_MOVE = 3,
    ADD_MISSION_RETURN = 4,
    DELETE_MISSION = 5,
    EDIT_MISSION = 6,
    PRINT_MISSIONS = 7,
    PRINT_DELETED_MISSIONS = 8,
    SWAP_MISSIONS = 9,
    RESTORE_MISSION = 10,
    SAVE_FILE = 11
};

class UI {
public:
    UI() = default;

    ~UI() = default;

    void start();

private:
    Operation operation;

    bool new_operaion(const int &mission_number);

    static std::unique_ptr<Mission> new_mission(const int &mission_number);
};