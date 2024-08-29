#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include "DatabaseConnection.h"
#include <vector>
#include <string>

class Room {
public:
    int id;
    std::string type;
    double price;
    bool isAvailable;
};

class RoomManager {
public:
    RoomManager(DatabaseConnection* dbConn);
    std::vector<Room> getAllRooms();
    void updateRoomStatus(int roomId, bool isAvailable);
    void addRoom(const Room& room);
    void removeRoom(int roomId);

private:
    DatabaseConnection* dbConn;
};

#endif
