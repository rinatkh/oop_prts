#pragma once

#include <iostream>

typedef struct data {
    float kHeading;
    float kPitch;
    float kRoll;
    char kHeadingStatus;
    float kQuaternion[4];
    float kTemperature;
    bool kDistortion;
    bool kCalStatus;
    float kAccelX;
    float kAccelY;
    float kAccelZ;
    float kMagX;
    float kMagY;
    float kMagZ;
    float kGyroX;
    float kGyroY;
    float kGyroZ;
} transfer_data_struct;

typedef struct data_bool {
    bool set_kHeading = false;
    bool set_kPitch = false;
    bool set_kRoll = false;
    bool set_kHeadingStatus = false;
    bool set_kQuaternion = false;
    bool set_kTemperature = false;
    bool set_kDistortion = false;
    bool set_kCalStatus = false;
    bool set_kAccelX = false;
    bool set_kAccelY = false;
    bool set_kAccelZ = false;
    bool set_kMagX = false;
    bool set_kMagY = false;
    bool set_kMagZ = false;
    bool set_kGyroX = false;
    bool set_kGyroY = false;
    bool set_kGyroZ = false;
} transfer_data_bool_struct;

enum IDs {
    kHeading = 5,
    kPitch = 24,
    kRoll = 25,
    kHeadingStatus = 79,
    kQuaternion = 77,
    kTemperature = 7,
    kDistortion = 8,
    kCalStatus = 9,
    kAccelX = 21,
    kAccelY = 22,
    kAccelZ = 23,
    kMagX = 27,
    kMagY = 28,
    kMagZ = 29,
    kGyroX = 74,
    kGyroY = 75,
    kGyroZ = 76
};

class Parser{
public:
    explicit Parser(const unsigned char* input_data, size_t size_of_input_data);
    Parser() = delete;
    ~Parser() = default;

    void output_parse();

private:
    const unsigned char *data_;
    size_t size_data_;

    transfer_data_struct transfer_data_;
    transfer_data_bool_struct transfer_data_set_;
};

