#pragma once

#include <string>
#include <sstream>

class Mission {
public:
    virtual ~Mission() = default;

    virtual bool set() = 0;

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    double get_depth() const {
        return depth;
    }

protected:
    virtual std::string get_coordinates() const;

    double x = 0.0;
    double y = 0.0;
    double depth = 0.0;
};

class Lift : public Mission {
public:
    explicit Lift(double depth) {
        depth = depth;
    }

    enum lift_dive_mode {
        VERTICAL,
        SPIRAL
    };

    void set_lift_dive_mode(lift_dive_mode mode) {
        mode_setting = mode;
    }

protected:
    std::string get_coordinates() const override;

    lift_dive_mode mode_setting = lift_dive_mode::VERTICAL;
};