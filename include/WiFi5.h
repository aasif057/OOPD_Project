#ifndef WIFI5_H
#define WIFI5_H

#include "WiFi.h"
#include "AccessPoint.h"

class WiFi5 : public WiFi {
public:
    WiFi5();  // Constructor declaration

    void simulate(int numUsers) override;
    void setNumUsers(int users) override;

private:
    int numUsers;
    double simulateCSI();
};

#endif
