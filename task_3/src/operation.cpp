#include "operation.h"

#include <iostream>

bool Operation::add_mission(std::unique_ptr<Mission> mission) {
    if (!mission) {
        return false;
    }

    if (!mission->set()) {
        return false;
    }

    list.push_back(std::move(mission));
    return true;
}

void Operation::print_list() {
    std::cout << missions();
}

bool Operation::delete_mission(const size_t &i) {
    if (list.empty()) {
        return false;
    }
    int mission_index = 0;
    for (const auto &k: list) {
        if (!k->is_del()) {
            mission_index++;
            if (mission_index == i) {
                k->delete_mission();
                return true;
            }
        }
    }
    return false;
}

void Operation::print_deleted_list() {
    std::cout << deleted_missions();
}

bool Operation::swap_missions(const size_t &i, const size_t &j) {
    size_t i_c = 0;
    size_t j_c = 0;
    size_t i_current = 0;
    size_t j_current = 0;
    size_t mission_index = 0;
    for (const auto &k: list) {
        if (!k->is_del()) {
            if (mission_index == i) {
                i_current = i_c;
            }
            if (mission_index == j) {
                j_current = j_c;
            }
            mission_index++;
        }
        i_c++;
        j_c++;
    }
    if (i >= 0 && i < mission_index && j >= 0 && j < mission_index) {
        std::swap(list[i_current], list[j_current]);
        return true;
    }
    return false;
}

void Operation::save_to_file() {
    if (list.empty()) {
        return;
    }

    open_file();
    auto out = missions();

    if (!file_output.write(out.c_str(), out.size())) {
        return;
    }
    file_output.close();
}

bool Operation::restore_mission(const size_t &i) {
    int mission_index = 0;
    for (const auto &k: list) {
        if (k->is_del()) {
            mission_index++;
        }
    }

    if (i >= 0 && i < mission_index - 1) {
        for (auto &k : list) {
            if (mission_index == i) {
                k->restore_mission();
                return true;
            }
            mission_index++;
        }
    }
    return false;
}

void Operation::open_file() {
    if (file_output.is_open()) {
        file_output.close();
    }
    file_output.open("list_of_actions.txt", std::ofstream::out | std::ofstream::trunc);
}

std::string Operation::missions() {
    std::stringstream str;
    int mission_index = 0;
    for (const auto &i: list) {
        if (!i->is_del()) {
            str << "Mission " << mission_index++ << "\n";
            str << i->get_mission();
            str << "\n";
        }
    }
    return str.str();
}

std::string Operation::deleted_missions() {
    std::stringstream str;
    int mission_index = 0;
    for (const auto &i: list) {
        if (i->is_del()) {
            str << "Mission " << mission_index++ << "\n";
            str << i->get_mission();
            str << "\n";
        }
    }
    return str.str();
}

bool Operation::change_mission(std::unique_ptr<Mission> mission, const size_t &i) {
    if (add_mission(std::move(mission))) {
        size_t mission_index = 0;
        for (size_t j = 0; j < list.size() - 1; j++) {
            if (!list[j]->is_del()) {
                mission_index++;
            }
        }
        if (swap_missions(i, mission_index)) {
            list.pop_back();
            return true;
        }
        return false;
    }
    return false;
}
