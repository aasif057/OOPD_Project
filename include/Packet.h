#ifndef PACKET_H
#define PACKET_H

#include <stdexcept>

class Packet {
private:
    double size; // Size in KB

public:
    Packet(double s) : size(s) {
        if (s <= 0) {
            throw std::invalid_argument("Packet size must be positive!");
        }
    }

    double getSize() const {
        return size;
    }

    void setSize(double s) {
        if (s <= 0) {
            throw std::invalid_argument("Packet size must be positive!");
        }
        size = s;
    }
};

#endif
