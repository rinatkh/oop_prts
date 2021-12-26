#pragma once

#include <string>
#include <sstream>

class Mission {
public:
    virtual ~Mission() = default;

    virtual bool set() = 0;

    virtual std::string get_mission() = 0;

    void delete_mission() { is_deleted = true; }

    void restore_mission() { is_deleted = false; }

    bool is_del() { return is_deleted; }

protected:
    virtual std::string get_coordinates() const;

    bool is_deleted = false;

    double x = 0.0;
    double y = 0.0;
    double depth = 0.0;

    double max_deep = 100.0;
    double min_deep = 0.0;
    double max_x = 5000.0;
    double min_x = -5000.0;
    double max_y = 5000.0;
    double min_y = -5000.0;
};

class Lift : public Mission {
public:
    enum lift_mode {
        VERTICAL,
        SPIRAL
    };

    enum sensor_mode {
        SENSOR_DEPTH,
        EHOLOT
    };

    //mode 0 - vertical, 1 - spiral; sensor 0 - sensor of the depth 1- eholot
    explicit Lift(double depth, int mode = static_cast<int>(lift_mode::VERTICAL),
                  int sensor = static_cast<int>(sensor_mode::SENSOR_DEPTH));

    Lift() = delete;

    ~Lift() override = default;

    bool set() override;

    std::string get_mission() override;

protected:
    std::string get_coordinates() const override;

    lift_mode mode_setting;

    sensor_mode sensor;
};

class Dive : public Mission {
public:
    enum dive_mode {
        VERTICAL,
        SPIRAL
    };

    enum sensor_mode {
        SENSOR_DEPTH,
        EHOLOT
    };

    //mode 0 - vertical, 1 - spiral; sensor 0 - sensor of the depth 1- eholot
    explicit Dive(double depth, int mode = static_cast<int>(dive_mode::VERTICAL),
                  int sensor = static_cast<int>(sensor_mode::SENSOR_DEPTH));

    Dive() = delete;

    ~Dive() override = default;

    bool set() override;

    std::string get_mission() override;

protected:
    std::string get_coordinates() const override;

    dive_mode mode_setting;

    sensor_mode sensor;
};

class Move : public Mission {
public:
    enum move_mode {
        STAY,
        PROCCED
    };

    enum motion {
        INDOT,
        LINE
    };

    // mode 0 - stay 1 - procced, motion - 0 in dot 1 - line
    explicit Move(double _x, double _y, double _accuracy = 1.0,
                  int mode = static_cast<int>(move_mode::STAY), int _motion_node = static_cast<int>(motion::LINE));

    Move() = delete;

    ~Move() override = default;

    bool set() override;

    std::string get_mission() override;

protected:
    std::string get_coordinates() const override;

    double accuracy;

    motion motion_node;

    move_mode mode_setting;

};

class Return : public Mission {
public:
    Return();

    ~Return() override = default;

    bool set() override;

    std::string get_mission() override;

protected:
    std::string get_coordinates() const override;
};
