#ifndef USER_H
#define USER_H

#include <iostream>
#include <stdexcept>

class User {
private:
    int id;
    double bandwidthUsage;
    double latency;
    double throughput;

public:
    User(int id) : id(id), bandwidthUsage(0.0), latency(0.0), throughput(0.0) {
        if (id <= 0) {
            throw std::invalid_argument("Invalid user ID!");
        }
    }

    int getId() const {
        return id;
    }

    void updateBandwidthUsage(double usage) {
        if (usage < 0) {
            throw std::invalid_argument("Bandwidth usage cannot be negative!");
        }
        bandwidthUsage += usage;
    }

    double getBandwidthUsage() const {
        return bandwidthUsage;
    }

    void setLatency(double lat) {
        latency = lat;
    }

    double getLatency() const {
        return latency;
    }

    void setThroughput(double rate) {
        throughput = rate;
    }

    double getThroughput() const {
        return throughput;
    }
};

#endif
