#include "WiFi5.h"
#include <iostream>

void WiFi5::setNumUsers(int users) {
    numUsers = users;
}

double WiFi5::simulateCSI() {
    return 0.2; // Simulate CSI packet transmission time (200 bytes = 0.2ms)
}

void WiFi5::simulate(int numUsers) {
    AccessPoint ap;
    for (int i = 1; i <= numUsers; i++) {
        ap.connectUser(User(i));  // Connecting users to the access point
    }

    double totalThroughput = 0;
    double totalLatency = 0;
    double maxLatency = 0;

    std::cout << "Simulating WiFi 5 with " << numUsers << " users...\n";

    for (int i = 0; i < numUsers; i++) {
        double csiTime = simulateCSI(); // Simulate CSI time
        double transmissionTime = 15.0; // Parallel communication time (ms)

        totalThroughput += 15.0; // Assume 15 ms throughput per user
        totalLatency += (csiTime + transmissionTime);
        if ((csiTime + transmissionTime) > maxLatency) {
            maxLatency = csiTime + transmissionTime;
        }
    }

    std::cout << "Throughput: " << totalThroughput << " KB/ms\n";
    std::cout << "Average Latency: " << totalLatency / numUsers << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";
}
