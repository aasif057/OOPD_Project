#include "WiFi5.h"
#include <iostream>
#include <cmath>

WiFi5::WiFi5() : numUsers(0) {}

void WiFi5::setNumUsers(int users) {
    numUsers = users;
}

double WiFi5::simulateCSI() {
    const double CSI_PACKET_SIZE = 200.0; // CSI packet size in bytes (200 bytes per user)
    const double DATA_RATE_Mbps = 433.3;  // WiFi 5 data rate in Mbps
    const double DATA_RATE_bps = DATA_RATE_Mbps * 1e6; // Convert to bits per second
    
    // Calculate CSI transmission time in seconds (200 bytes = 200 * 8 bits)
    double timeForCSI = (CSI_PACKET_SIZE * 8) / DATA_RATE_bps;  // Time in seconds
    return timeForCSI * 1000;  // Return time in milliseconds
}

void WiFi5::simulate(int numUsers) {
    // Step 1: Simulate CSI transmission for all users
    double totalCSITransmissionTime = numUsers * simulateCSI(); // Time for all users' CSI transmission

    // Step 2: Time for parallel transmission (fixed for all users)
    const double parallelTransmissionTime = 15.0;  // Parallel communication time in ms
    
    // Step 3: Calculate total data transmitted during parallel transmission
    double totalDataTransmitted = numUsers * 1024 * 8;  // Each user sends 1 KB of data (in bits)

    // Step 4: Calculate total time (CSI + parallel transmission)
    double totalTime = totalCSITransmissionTime + parallelTransmissionTime;
    
    // Step 5: Calculate throughput (in Mbps)
    double throughput = (totalDataTransmitted / 1e6) / parallelTransmissionTime;  // Throughput in Mbps
    
    // Step 6: Calculate average and maximum latency
    double averageLatency = totalTime ;  // Average latency per user (rough estimate)
    double maxLatency = totalTime;  // Max latency (since we assume all users transmit in parallel)
    
    // Output the results
    std::cout << "Throughput: " << throughput << " Mbps" << std::endl;
    std::cout << "Average Latency: " << averageLatency << " ms" << std::endl;
    std::cout << "Maximum Latency: " << maxLatency << " ms" << std::endl;
}
