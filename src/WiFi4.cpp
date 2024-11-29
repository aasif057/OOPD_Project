#include "WiFi4.h"
#include <iostream>
#include <vector>
#include <algorithm> // for max_element

// Constants for WiFi 4 Simulation
const double DATA_RATE = 66.67; // Mbps (Theoretical data rate for 256-QAM, 5/6 coding rate, 20 MHz bandwidth)
const double PACKET_SIZE = 1.0; // KB
const double MAX_BACKOFF_TIME = 0.02; // Maximum backoff time (20 ms)

// Set number of users
void WiFi4::setNumUsers(int users) {
    numUsers = users;
}

// Simulate WiFi 4 communication
void WiFi4::simulate(int numUsers) {
    AccessPoint ap;

    // Connect users
    for (int i = 1; i <= numUsers; i++) {
        ap.connectUser(User(i));
    }

    double totalThroughput = 0.0;
    double totalLatency = 0.0;
    double maxLatency = 0.0;

    // Store latency for each user
    std::vector<double> latencies(numUsers);

    // Loop through users to simulate transmission
    for (int i = 0; i < numUsers; i++) {
        double backoffTime = simulateBackoff();  // Simulate random backoff time
        double transmissionTime = calculateTransmissionTime(PACKET_SIZE, DATA_RATE); // Transmission time for the packet
        double latency = transmissionTime + backoffTime;  // Total latency for this user

        latencies[i] = latency;
        totalLatency += latency;

        // Throughput per user: how much data is transmitted per unit of time
        double userThroughput = (PACKET_SIZE * 8) / (transmissionTime + backoffTime); // Kbps per user
        totalThroughput += userThroughput;

        if (latency > maxLatency) {
            maxLatency = latency;
        }
    }

    // Calculate average throughput and latency
    double averageThroughput = totalThroughput / numUsers; // Average throughput (in Kbps per user)
    double averageLatency = totalLatency / numUsers;

    // Output results
    std::cout << "Simulating WiFi 4 with " << numUsers << " users...\n";
    std::cout << "Throughput: " << averageThroughput / 1000 << " Mbps\n"; // Convert Kbps to Mbps
    std::cout << "Average Latency: " << averageLatency << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";
}

// Calculate transmission time based on packet size and data rate
double WiFi4::calculateTransmissionTime(double packetSize, double dataRate) {
    // Transmission time in seconds
    double transmissionTime = (packetSize * 8) / (dataRate * 1000); // Convert Mbps to Kbps for packet size in KB
    return transmissionTime;
}

// Simulate a random backoff time (uniform distribution)
double WiFi4::simulateBackoff() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> backoffDist(0.0, MAX_BACKOFF_TIME); // Backoff time between 0 and MAX_BACKOFF_TIME

    return backoffDist(gen);
}
