#include "WiFi6.h"
#include <iostream>

void WiFi6::setNumUsers(int users) {
    numUsers = users;
}

double WiFi6::calculateThroughput(double subChannelSize) {
    const double totalChannelBandwidth = 20.0; // 20 MHz total bandwidth
    const double totalDataRate = 4333.0; // WiFi 6 data rate in Mbps for 20 MHz channel
    // Calculate data rate for the sub-channel
    double subChannelDataRate = (subChannelSize / totalChannelBandwidth) * totalDataRate;
    // Throughput for each user is data rate * transmission time (5ms = 0.005s)
    return subChannelDataRate * 0.005; // Throughput in Mbps
}

void WiFi6::allocateSubChannels(FrequencyChannel& channel, int userIndex) {
    // Example: Allocate sub-channels of 2 MHz, 4 MHz, or 10 MHz in round-robin fashion
    double subChannelSize;
    switch (userIndex % 3) {
        case 0: subChannelSize = 2.0; break;  // 2 MHz
        case 1: subChannelSize = 4.0; break;  // 4 MHz
        case 2: subChannelSize = 10.0; break; // 10 MHz
        default: subChannelSize = 2.0; break; // Default to 2 MHz
    }
    // Allocate this sub-channel to the user
    channel.allocateSubChannel(subChannelSize);
}

void WiFi6::simulate(int numUsers) {
    FrequencyChannel channel(20.0); // 20 MHz total bandwidth
    double totalThroughput = 0;
    double totalLatency = 0;
    double maxLatency = 0;

    std::cout << "Simulating WiFi 6 with " << numUsers << " users...\n";

    // Round-robin scheduling of users
    for (int i = 0; i < numUsers; i++) {
        allocateSubChannels(channel, i); // Allocate sub-channel for the user

        double subChannelSize = (i % 3 == 0) ? 2.0 : (i % 3 == 1) ? 4.0 : 10.0; // Example allocation
        double throughput = calculateThroughput(subChannelSize); // Calculate throughput based on sub-channel size
        totalThroughput += throughput;  // Add this user's throughput to total throughput

        double transmissionTime = 5.0; // Transmission time per user in ms
        totalLatency += transmissionTime;

        if (transmissionTime > maxLatency) {
            maxLatency = transmissionTime; // Track maximum latency
        }
    }

    // Print results
    std::cout << "Throughput: " << totalThroughput << " Mbps\n";
    std::cout << "Average Latency: " << totalLatency / numUsers << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";
}
