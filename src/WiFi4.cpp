#include "WiFi4.h"
#include <iostream>
#include <random>
#include <vector>
#include <algorithm> // For max_element

void WiFi4::setNumUsers(int users) {
    numUsers = users;
}

double WiFi4::calculateTransmissionTime(double packetSize, double dataRate) {
    return (packetSize * 8) / (dataRate * 1000); // Time in ms
}

double WiFi4::simulateBackoff() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> backoffDist(0.0, 2.0); // Backoff time between 0 and 2ms
    return backoffDist(gen);
}

void WiFi4::simulate(int numUsers) {
    AccessPoint ap;
    for (int i = 1; i <= numUsers; i++) {
        ap.connectUser(User(i));  // Connecting users to the access point
    }

    const double dataRate = 133.33; // Mbps
    const double packetSize = 1.0;  // KB
    double transmissionTime = calculateTransmissionTime(packetSize, dataRate);

    std::vector<double> latencies(numUsers); // To store latency for each user
    double totalThroughput = 0.0;
    double totalLatency = 0.0;

    for (int i = 0; i < numUsers; i++) {
        if (!ap.isChannelFree()) {
            double backoffTime = simulateBackoff(); // Random backoff time
            std::cout << "Channel busy, backing off for " << backoffTime << " ms\n";
            transmissionTime += backoffTime;
        }

        double latency = transmissionTime; // Latency after successful transmission
        latencies[i] = latency;
        totalThroughput += packetSize; // Throughput increases by 1 KB for each successful packet
        totalLatency += latency;
    }

    double averageLatency = totalLatency / numUsers;
    double maxLatency = *std::max_element(latencies.begin(), latencies.end());

    std::cout << "Simulating WiFi 4 with " << numUsers << " users...\n";
    std::cout << "Throughput: " << totalThroughput / numUsers << " KB/ms\n";
    std::cout << "Average Latency: " << averageLatency << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";
}
