#include "BookingUI.h"
#include <iostream>

BookingUI::BookingUI(BookingManager* bookingManager) : bookingManager(bookingManager) {}

void BookingUI::bookRoom() {
    Booking booking;
    std::cout << "Enter Customer ID: ";
    std::cin >> booking.customerId;
    std::cout << "Enter Room ID: ";
    std::cin >> booking.roomId;
    std::cout << "Enter Check-in Date (YYYY-MM-DD): ";
    std::cin >> booking.checkInDate;
    std::cout << "Enter Check-out Date (YYYY-MM-DD): ";
    std::cin >> booking.checkOutDate;

    bookingManager->bookRoom(booking);
    std::cout << "Room booked successfully.\n";
}

void BookingUI::cancelBooking() {
    int bookingId;
    std::cout << "Enter Booking ID to cancel: ";
    std::cin >> bookingId;

    bookingManager->cancelBooking(bookingId);
    std::cout << "Booking canceled successfully.\n";
}

void BookingUI::displayBookingsByCustomer(int customerId) {
    std::vector<Booking> bookings = bookingManager->getBookingsByCustomer(customerId);
    for (const Booking& booking : bookings) {
        std::cout << "Booking ID: " << booking.id << ", Room ID: " << booking.roomId << ", Check-in: " << booking.checkInDate << ", Check-out: " << booking.checkOutDate << "\n";
    }
}
