#ifndef WIFI4_H
#define WIFI4_H

#include "WiFi.h"
#include "AccessPoint.h"
#include <random>

class WiFi4 : public WiFi {
public:
    void simulate(int numUsers) override;
    void setNumUsers(int users) override;
private:
    int numUsers;
    double calculateTransmissionTime(double packetSize, double dataRate);
    double simulateBackoff();
};

#endif
