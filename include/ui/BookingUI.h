#ifndef BOOKING_UI_H
#define BOOKING_UI_H

#include "BookingManager.h"

class BookingUI {
public:
    BookingUI(BookingManager* bookingManager);
    void bookRoom();
    void cancelBooking();
    void displayBookingsByCustomer(int customerId);

private:
    BookingManager* bookingManager;
};

#endif
