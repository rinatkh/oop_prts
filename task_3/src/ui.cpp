#include "ui.h"

#include <iostream>

void UI::start() {
    while (true) {
        std::cout << "Введите задачу для выполнения.\n"
                     "цифра 1 - добавление миссии LIFT;\nцифра 2 - добавление миссии DIVE;\nцифра 3 - Добавление миссии MOVE;\n"
                     "цифра 4 - добавление миссии RETURN;\n"
                     "цифра 5 - удаление задачи;\nцифра 6 - изменить задачу из списка;\n"
                     "цифра 7 - вывод задач;\nцифра 8 - вывод удаленных задач\n"
                     "цифра 9 - переустановить задачи\nцифра 10 - восстановить задачу\nцифра 11 - сохранить в файл\n"
                  << std::endl;

        int number = 0;
        std::cin >> number;
        if (number >= 0 && number < 12) {
            if (!new_operaion(number)) {
                break;
            }
        } else {
            std::cout << "Некорректное действие" << std::endl;
        }
    }
    std::cout << "Завершение";
}

bool UI::new_operaion(const int &mission_number) {
    switch (mission_number) {
        case ADD_MISSION_DIVE: {
            case ADD_MISSION_LIFT: {
                case ADD_MISSION_MOVE: {
                    case ADD_MISSION_RETURN: {
                        return operation.add_mission(new_mission(mission_number));
                    }
                }
            }
        }

        case DELETE_MISSION: {
            operation.print_list();
            std::cout << "Выберите задачу для удаления." << std::endl;
            size_t idx;
            std::cin >> idx;
            return operation.delete_mission(idx);
        }
        case EDIT_MISSION: {
            operation.print_list();
            std::cout << "Выберите задачу (индекс)." << std::endl;
            size_t idx;
            std::cin >> idx;
            std::cout
                    << "Выберите тип миссии.\nцифра 1 - добавление миссии LIFT;\nцифра 2 - добавление миссии DIVE;\nцифра 3 - Добавление миссии MOVE;\n"
                       "цифра 4 - добавление миссии RETURN;\n";
            while (true) {
                int number;
                std::cin >> number;
                if (number >= 0 && number < 5) {
                    return operation.change_mission(new_mission(number), idx);
                } else {
                    std::cout << "Некорректный тип мисси, введите тип миссии ещё раз." << std::endl;
                }
            }
        }
        case PRINT_MISSIONS: {
            operation.print_list();
            return true;
        }
        case PRINT_DELETED_MISSIONS: {
            operation.print_deleted_list();
            return true;
        }
        case SWAP_MISSIONS: {
            operation.print_list();
            std::cout << "Выберите две миссии, чтобы поменять их местами (по индексу из списка)."
                      << std::endl;
            size_t idx1, idx2;
            std::cin >> idx1 >> idx2;
            return operation.swap_missions(idx1, idx2);
        }
        case RESTORE_MISSION: {
            operation.print_deleted_list();

            std::cout << "Выберите задачу для вставки." << std::endl;
            size_t idx;
            std::cin >> idx;
            return operation.restore_mission(idx);
        }
        case SAVE_FILE: {
            operation.save_to_file();
            return true;
        }
        default:
            return false;
    }
}

std::unique_ptr<Mission> UI::new_mission(const int &mission_number) {
    std::unique_ptr<Mission> mission;
    if (mission_number == ADD_MISSION_DIVE || mission_number == ADD_MISSION_LIFT) {
        int sensor; // 0 - sensor of the depth 1- eholot
        double depth;
        int mode; //0 - vertical, 1 - spiral

        std::cout
                << "Введите способ задания глубины (0 - датчик глубины (глубина) ; 1 - эхолот (отстояние)): "
                << std::endl;
        while (true) {
            std::cin >> sensor;
            if (sensor != 0 && sensor != 1) {
                std::cout
                        << "Неверный способ задания глубины. Введите способ задания глубины ещё раз."
                        << std::endl;
                std::cin >> sensor;
            } else {
                break;
            }
        }

        std::cout << "Введите глубину погружения(отстояния): " << std::endl;
        std::cin >> depth;

        std::cout << "Введите тип погружения (0 - вертикально; 1 - по спирали): " << std::endl;
        while (true) {
            std::cin >> mode;
            if (mode != 0 && mode != 1) {
                std::cout << "Неверный тип погружения. Введите тип погружения ещё раз."
                          << std::endl;
                std::cin >> mode;
            } else {
                break;
            }
        }
        if (mission_number == ADD_MISSION_DIVE) {
            mission = std::make_unique<Dive>(depth, mode, sensor);
        } else {
            mission = std::make_unique<Lift>(depth, mode, sensor);
        }
    } else if (mission_number == ADD_MISSION_MOVE) {
        int newX;
        int newY;
        double accuracy;
        int motion_node; // 0 - выход в точку; 1 - движение вдоль прямой
        int node; // 0 - на постоянной глубине; 1 - на постоянном отстоянии от дна
        std::cout << "Введите тип выхода (0 - выход в точку ; 1 - движение вдоль прямой): "
                  << std::endl;
        while (true) {
            std::cin >> motion_node;
            if (motion_node != 0 && motion_node != 1) {
                std::cout << "Неверный тип выхода. Введите тип выхода ещё раз." << std::endl;
                std::cin >> motion_node;
            } else {
                break;
            }
        }

        std::cout
                << "Введите тип выхода(0 - на постоянной глубине; 1 - на постоянном отстоянии от дна): "
                << std::endl;
        while (true) {
            std::cin >> node;
            if (node != 0 && node != 1) {
                std::cout << "Неверный тип выхода. Введите тип выхода ещё раз." << std::endl;
                std::cin >> node;
            } else {
                break;
            }
        }

        std::cout << "Введите координату X: " << std::endl;
        std::cin >> newX;

        std::cout << "Введите координату Y: " << std::endl;
        std::cin >> newY;

        std::cout << "Введите точность " << std::endl;
        std::cin >> accuracy;
        mission = std::make_unique<Move>(newX, newY, accuracy, node, motion_node);
    } else if (mission_number == ADD_MISSION_RETURN) {
        mission = std::make_unique<Return>();
        std::cout << "Вывод в 0 установлен" << std::endl;
    }
    return std::move(mission);
}
