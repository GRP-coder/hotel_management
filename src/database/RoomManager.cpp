#include "RoomManager.h"
#include <iostream>

RoomManager::RoomManager(DatabaseConnection* dbConn) : dbConn(dbConn) {}

std::vector<Room> RoomManager::getAllRooms() {
    std::vector<Room> rooms;
    MYSQL* conn = dbConn->getConnection();
    MYSQL_RES* res;
    MYSQL_ROW row;

    if (mysql_query(conn, "SELECT * FROM rooms")) {
        std::cerr << "Failed to fetch rooms\n";
        return rooms;
    }

    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res))) {
        Room room;
        room.id = atoi(row[0]);
        room.type = row[1];
        room.price = atof(row[2]);
        room.isAvailable = atoi(row[3]);
        rooms.push_back(room);
    }

    mysql_free_result(res);
    return rooms;
}

void RoomManager::updateRoomStatus(int roomId, bool isAvailable) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "UPDATE rooms SET isAvailable = " + std::to_string(isAvailable) + " WHERE id = " + std::to_string(roomId);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to update room status\n";
    }
}

void RoomManager::addRoom(const Room& room) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "INSERT INTO rooms (type, price, isAvailable) VALUES ('" + room.type + "', " + std::to_string(room.price) + ", " + std::to_string(room.isAvailable) + ")";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to add room\n";
    }
}

void RoomManager::removeRoom(int roomId) {
    MYSQL* conn = dbConn->getConnection();
    std::string query = "DELETE FROM rooms WHERE id = " + std::to_string(roomId);
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Failed to remove room\n";
    }
}
