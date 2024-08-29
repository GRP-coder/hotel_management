#include "BookingManager.h"
#include <iostream>

BookingManager::BookingManager(DatabaseConnection* dbConn) : dbConn(dbConn) {}

void BookingManager::bookRoom(const Booking& booking) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "INSERT INTO bookings (customerId, roomId, checkInDate, checkOutDate) VALUES (" +
        std::to_string(booking.customerId) + ", " + std::to_string(booking.roomId) + ", '" + booking.checkInDate + "', '" + booking.checkOutDate + "')";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to book room\n";
    }

    std::string updateRoomStatusQuery = "UPDATE rooms SET isAvailable = 0 WHERE id = " + std::to_string(booking.roomId);
    if (mysql_query(conn, updateRoomStatusQuery.c_str())) {
        std::cerr << "Failed to update room status\n";
    }
}

void BookingManager::cancelBooking(int bookingId) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "DELETE FROM bookings WHERE id = " + std::to_string(bookingId);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to cancel booking\n";
    }
}

std::vector<Booking> BookingManager::getBookingsByCustomer(int customerId) {
    std::vector<Booking> bookings;
    MYSQL* conn = dbConn->getConnection();
    MYSQL_RES* res;
    MYSQL_ROW row;

    std::string query = "SELECT * FROM bookings WHERE customerId = " + std::to_string(customerId);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to fetch bookings\n";
        return bookings;
    }

    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res))) {
        Booking booking;
        booking.id = atoi(row[0]);
        booking.customerId = atoi(row[1]);
        booking.roomId = atoi(row[2]);
        booking.checkInDate = row[3];
        booking.checkOutDate = row[4];
        bookings.push_back(booking);
    }

    mysql_free_result(res);
    return bookings;
}
