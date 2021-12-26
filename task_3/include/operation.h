#pragma once

#include <vector>
#include <memory>
#include <fstream>

#include "mission.h"

class Operation {
public:
    Operation() = default;

    ~Operation() = default;

    bool add_mission(std::unique_ptr<Mission> mission);

    void print_list();

    bool delete_mission(const size_t &i);

    void print_deleted_list();

    bool swap_missions(const size_t &i, const size_t &j);

    void save_to_file();

    bool restore_mission(const size_t &i);

    bool change_mission(std::unique_ptr<Mission> mission, const size_t &i);

private:
    std::string missions();

    std::string deleted_missions();

    void open_file();

    std::vector<std::unique_ptr<Mission>> list;

    std::ofstream file_output;
};