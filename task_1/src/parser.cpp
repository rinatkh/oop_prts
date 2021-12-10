#include "parser.h"

#include <cstring>
#include <sstream>

static float
swap_endian_float(const unsigned char *sting_of_data, size_t index, size_t size_of_data) {

    if (index + 4 > size_of_data) {
        return -1;
    }
    float retVal;
    auto *returnFloat = (unsigned char *) &retVal;

    for (int i = 0; i < sizeof(float); ++i) {
        returnFloat[i] = sting_of_data[index + sizeof(float) - 1 - i];
    }

    return retVal;
}

Parser::Parser(const unsigned char *input_data, size_t size_of_input_data) : data_(input_data),
                                                                             size_data_(size_of_input_data),
                                                                             transfer_data_(){
    for (size_t i = 0; i < size_data_; ++i) {
        switch (int(input_data[i])) {
            case kHeading: {
                transfer_data_.kHeading = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kHeading = true;
                i += sizeof(float);
                break;
            }
            case kPitch: {
                transfer_data_.kPitch = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kPitch = true;
                i += sizeof(float);
                break;
            }
            case kRoll: {
                transfer_data_.kRoll = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kRoll = true;
                i += sizeof(float);
                break;
            }
            case kHeadingStatus: {
                memcpy(&transfer_data_.kHeadingStatus, &input_data[i + 1], sizeof(char));
                transfer_data_set_.set_kHeadingStatus = true;
                i += sizeof(char);
                break;
            }
            case kQuaternion: {
                for (float &quat: transfer_data_.kQuaternion) {
                    quat = swap_endian_float(input_data, i + 1, size_of_input_data);
                    i += sizeof(float);
                }
                transfer_data_set_.set_kQuaternion = true;
                break;
            }
            case kTemperature: {
                transfer_data_.kTemperature = swap_endian_float(input_data, i + 1,
                                                                size_of_input_data);
                i += sizeof(float);
                transfer_data_set_.set_kTemperature = true;
                break;
            }
            case kDistortion: {
                memcpy(&transfer_data_.kDistortion, &input_data[i + 1], sizeof(bool));
                transfer_data_set_.set_kDistortion = true;
                i += sizeof(bool);
                break;
            }
            case kCalStatus: {
                memcpy(&transfer_data_.kCalStatus, &input_data[i + 1], sizeof(bool));
                transfer_data_set_.set_kCalStatus = true;
                i += sizeof(bool);
                break;
            }
            case kAccelX: {
                transfer_data_.kAccelX = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kAccelX = true;
                i += sizeof(float);
                break;
            }
            case kAccelY: {
                transfer_data_.kAccelY = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kAccelY = true;
                i += sizeof(float);
                break;
            }
            case kAccelZ: {
                transfer_data_.kAccelZ = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kAccelZ = true;
                i += sizeof(float);
                break;
            }
            case kMagX: {
                transfer_data_.kMagX = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kMagX = true;
                i += sizeof(float);
                break;
            }
            case kMagY: {
                transfer_data_.kMagY = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kMagY = true;
                i += sizeof(float);
                break;
            }
            case kMagZ: {
                transfer_data_.kMagZ = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kMagZ = true;
                i += sizeof(float);
                break;
            }
            case kGyroX: {
                transfer_data_.kGyroX = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kGyroX = true;
                i += sizeof(float);
                break;
            }
            case kGyroY: {
                transfer_data_.kGyroY = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kGyroY = true;
                i += sizeof(float);
                break;
            }
            case kGyroZ: {
                transfer_data_.kGyroZ = swap_endian_float(input_data, i + 1, size_of_input_data);
                transfer_data_set_.set_kGyroZ = true;
                i += sizeof(float);
                break;
            }
            default:
                break;
        }
    }
}

template<typename T>
static std::string print_if(T t, bool is_set) {
    std::stringstream element;
    if (is_set) {
        element << t;
    } else {
        element << '-';
    }
    return element.str();
}

void Parser::output_parse() {
    std::cout << "kHeading:       " << print_if(transfer_data_.kHeading,transfer_data_set_.set_kHeading) << "\n";
    std::cout << "kPitch:         " << print_if(transfer_data_.kPitch, transfer_data_set_.set_kPitch) << "\n";
    std::cout << "kRoll:          " << print_if(transfer_data_.kRoll, transfer_data_set_.set_kRoll) << "\n";
    std::cout << "kHeadingStatus: " << print_if(static_cast<int>(transfer_data_.kHeadingStatus),transfer_data_set_.set_kHeadingStatus) << "\n";
    std::cout << "kQuaternion:    " << print_if(transfer_data_.kQuaternion[0], transfer_data_set_.set_kQuaternion) << "\n";
    std::cout << "kTemperature:   " << print_if(transfer_data_.kTemperature, transfer_data_set_.set_kTemperature) << "\n";
    std::cout << "kDistortion:    " << print_if(transfer_data_.kDistortion, transfer_data_set_.set_kDistortion) << "\n";
    std::cout << "kCalStatus:     " << print_if(transfer_data_.kCalStatus,transfer_data_set_.set_kCalStatus) << "\n";
    std::cout << "kAccelX:        " << print_if(transfer_data_.kAccelX, transfer_data_set_.set_kAccelX) << "\n";
    std::cout << "kAccelY:        " << print_if(transfer_data_.kAccelY, transfer_data_set_.set_kAccelY) << "\n";
    std::cout << "kAccelZ:        " << print_if(transfer_data_.kAccelZ, transfer_data_set_.set_kAccelZ) << "\n";
    std::cout << "kMagX:          " << print_if(transfer_data_.kMagX, transfer_data_set_.set_kMagX) << "\n";
    std::cout << "kMagY:          " << print_if(transfer_data_.kMagY, transfer_data_set_.set_kMagY) << "\n";
    std::cout << "kMagZ:          " << print_if(transfer_data_.kMagZ, transfer_data_set_.set_kMagZ) << "\n";
    std::cout << "kGyroX:         " << print_if(transfer_data_.kGyroX, transfer_data_set_.set_kGyroX) << "\n";
    std::cout << "kGyroY:         " << print_if(transfer_data_.kGyroY, transfer_data_set_.set_kGyroY) << "\n";
    std::cout << "kGyroZ:         " << print_if(transfer_data_.kGyroZ, transfer_data_set_.set_kGyroZ) << "\n";
}
