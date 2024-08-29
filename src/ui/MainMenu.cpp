#include "MainMenu.h"
#include <iostream>
#include "RoomUI.h"
#include "CustomerUI.h"
#include "BookingUI.h"

void MainMenu::show() {
    int choice;

    do {
        std::cout << "1. Manage Rooms\n";
        std::cout << "2. Manage Customers\n";
        std::cout << "3. Manage Bookings\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Call RoomUI functions
                break;
            case 2:
                // Call CustomerUI functions
                break;
            case 3:
                // Call BookingUI functions
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}
