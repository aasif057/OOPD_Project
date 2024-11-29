#include <iostream>
#include <memory>  // For std::unique_ptr
#include "WiFi4.h"
#include "WiFi5.h"
#include "WiFi6.h"

int main() {
    try {
        int wifiType, users;

        // Input WiFi type
        std::cout << "Enter WiFi type (4 for WiFi4, 5 for WiFi5, 6 for WiFi6): ";
        std::cin >> wifiType;

        // Input number of users
        std::cout << "Enter number of users: ";
        std::cin >> users;

        std::unique_ptr<WiFi> wifi;  // Using unique_ptr for automatic memory management

        // Switch case to choose the appropriate WiFi communication type
        switch (wifiType) {
            case 4:
                wifi = std::make_unique<WiFi4>();
                break;
            case 5:
                wifi = std::make_unique<WiFi5>();
                break;
            case 6:
                wifi = std::make_unique<WiFi6>();
                break;
            default:
                throw std::invalid_argument("Invalid WiFi type entered!");
        }

        // Set the number of users in the WiFi object (assuming the WiFi classes have a setter for users)
        wifi->setNumUsers(users);

        // Call the simulate method of the selected WiFi type with the number of users
        wifi->simulate(users);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
