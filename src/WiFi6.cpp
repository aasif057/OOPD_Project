#include "WiFi6.h"
#include <iostream>

void WiFi6::setNumUsers(int users) {
    numUsers = users;
}

void WiFi6::allocateSubChannels(FrequencyChannel& channel) {
    // Allocate sub-channels for each user (assuming fixed sub-channel sizes)
    channel.allocateSubChannel(2.0); // Example sub-channel size (2 MHz)
}

void WiFi6::simulate(int numUsers) {
    FrequencyChannel channel(20.0); // 20 MHz total bandwidth
    double totalThroughput = 0;
    double totalLatency = 0;
    double maxLatency = 0;

    std::cout << "Simulating WiFi 6 with " << numUsers << " users...\n";

    for (int i = 0; i < numUsers; i++) {
        allocateSubChannels(channel); // Allocate sub-channels for the user
        double transmissionTime = 5.0; // Transmission time per user in ms
        totalThroughput += 5.0;        // Add throughput per user
        totalLatency += transmissionTime;

        if (transmissionTime > maxLatency) {
            maxLatency = transmissionTime;
        }
    }

    std::cout << "Throughput: " << totalThroughput << " KB/ms\n";
    std::cout << "Average Latency: " << totalLatency / numUsers << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";
}
