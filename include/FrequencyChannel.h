#ifndef FREQUENCYCHANNEL_H
#define FREQUENCYCHANNEL_H

#include <vector>
#include <stdexcept>

class FrequencyChannel {
private:
    double bandwidth;  // Total bandwidth in MHz
    std::vector<double> subChannels;

public:
    FrequencyChannel(double bw) : bandwidth(bw) {
        if (bw <= 0) {
            throw std::invalid_argument("Bandwidth must be positive!");
        }
    }

    // Allocate sub-channel based on the bandwidth available
    void allocateSubChannel(double subChannelBW) {
        if (subChannelBW <= 0 || subChannelBW > bandwidth) {
            throw std::invalid_argument("Invalid sub-channel bandwidth!");
        }
        subChannels.push_back(subChannelBW);
        bandwidth -= subChannelBW;
    }

    // Reset the channel (useful for WiFi 6 channel reallocation)
    void reset() {
        bandwidth = 20;  // Reset to total bandwidth
        subChannels.clear();
    }

    const std::vector<double>& getSubChannels() const {
        return subChannels;
    }

    double getRemainingBandwidth() const {
        return bandwidth;
    }
};

#endif
