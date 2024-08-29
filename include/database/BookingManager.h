#ifndef BOOKING_MANAGER_H
#define BOOKING_MANAGER_H

#include "DatabaseConnection.h"
#include <string>

class Booking {
public:
    int id;
    int customerId;
    int roomId;
    std::string checkInDate;
    std::string checkOutDate;
};

class BookingManager {
public:
    BookingManager(DatabaseConnection* dbConn);
    void bookRoom(const Booking& booking);
    void cancelBooking(int bookingId);
    std::vector<Booking> getBookingsByCustomer(int customerId);

private:
    DatabaseConnection* dbConn;
};

#endif
