#ifndef WIFI6_H
#define WIFI6_H

#include "WiFi.h"
#include "FrequencyChannel.h"

class WiFi6 : public WiFi {
public:
    void simulate(int numUsers) override;
    void setNumUsers(int users) override;
private:
    int numUsers;
    void allocateSubChannels(FrequencyChannel& channel, int userIndex);
    double calculateThroughput(double subChannelSize);
};

#endif
