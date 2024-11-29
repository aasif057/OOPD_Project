#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include <vector>
#include <iostream>
#include <random>
#include "User.h"
#include "Packet.h"

class AccessPoint {
private:
    std::vector<User> connectedUsers;
    bool channelBusy = false;  // Tracks channel state
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> backoffDist;

public:
    AccessPoint() : gen(rd()), backoffDist(0, 2.0) {} // Max backoff time is 2ms

    void connectUser(const User& user) {
        connectedUsers.push_back(user);
        std::cout << "User connected. Total users: " << connectedUsers.size() << "\n";
    }

    const std::vector<User>& getUsers() const {
        return connectedUsers;
    }

    bool isChannelFree() const {
        return !channelBusy;
    }

    void setChannelState(bool state) {
        channelBusy = state;
    }

    // Simulate sniffing and backoff behavior
    double simulateBackoff() {
        return backoffDist(gen);  // Generate random backoff time
    }

    void broadcastPacket(const Packet& packet) {
        for (const auto& user : connectedUsers) {
            std::cout << "Broadcasting packet to User " << user.getId() << "\n";
        }
    }

    void transmitData() {
        // Simulate the transmission process, including channel sniffing and backoff
        if (!isChannelFree()) {
            double backoffTime = simulateBackoff();
            std::cout << "Channel busy. Backing off for " << backoffTime << " ms\n";
        } else {
            std::cout << "Channel is free. Transmitting data...\n";
        }
    }
};

#endif
