#ifndef WIFI_H
#define WIFI_H

#include <iostream>

class WiFi {
public:
    virtual void simulate(int numUsers) = 0;  // Pure virtual function
    virtual void setNumUsers(int users) = 0;
    virtual ~WiFi() = default;
};

#endif

