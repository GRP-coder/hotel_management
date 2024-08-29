#include <iostream>
#include "database/DatabaseConnection.h"
#include "ui/MainMenu.h"
#include "database/RoomManager.h"
#include "database/CustomerManager.h"
#include "database/BookingManager.h"
#include "ui/RoomUI.h"
#include "ui/CustomerUI.h"
#include "ui/BookingUI.h"
#include "utils/Authentication.h"

int main() {
    // Initialize database connection
    DatabaseConnection dbConn("localhost", "root", "yourpassword", "hotel_management");

    if (!dbConn.connect()) {
        std::cerr << "Failed to connect to the database. Exiting...\n";
        return 1;
    }

    // Authentication
    Authentication auth(&dbConn);
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (!auth.login(username, password)) {
        std::cerr << "Login failed. Exiting...\n";
        return 1;
    }

    // Initialize managers
    RoomManager roomManager(&dbConn);
    CustomerManager customerManager(&dbConn);
    BookingManager bookingManager(&dbConn);

    // Initialize UI components
    RoomUI roomUI(&roomManager);
    CustomerUI customerUI(&customerManager);
    BookingUI bookingUI(&bookingManager);

    // Main menu
    MainMenu mainMenu;
    mainMenu.show();

    return 0;
}
