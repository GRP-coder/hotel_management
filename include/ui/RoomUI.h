#ifndef ROOM_UI_H
#define ROOM_UI_H

#include "RoomManager.h"

class RoomUI {
public:
    RoomUI(RoomManager* roomManager);
    void displayRooms();
    void addRoom();
    void removeRoom();
    void updateRoomStatus();

private:
    RoomManager* roomManager;
};

#endif
