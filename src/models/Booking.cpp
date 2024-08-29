#include "Booking.h"

Booking::Booking() : id(0), customerId(0), roomId(0), checkInDate(""), checkOutDate("") {}

Booking::Booking(int id, int customerId, int roomId, const std::string& checkInDate, const std::string& checkOutDate)
    : id(id), customerId(customerId), roomId(roomId), checkInDate(checkInDate), checkOutDate(checkOutDate) {}
