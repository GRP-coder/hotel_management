#ifndef BOOKING_H
#define BOOKING_H

#include <string>

class Booking {
public:
    int id;
    int customerId;
    int roomId;
    std::string checkInDate;
    std::string checkOutDate;

    Booking();
    Booking(int id, int customerId, int roomId, const std::string& checkInDate, const std::string& checkOutDate);
};

#endif // BOOKING_H
