#include "RoomUI.h"
#include <iostream>

RoomUI::RoomUI(RoomManager* roomManager) : roomManager(roomManager) {}

void RoomUI::displayRooms() {
    std::vector<Room> rooms = roomManager->getAllRooms();
    for (const Room& room : rooms) {
        std::cout << "Room ID: " << room.id << ", Type: " << room.type << ", Price: " << room.price << ", Available: " << (room.isAvailable ? "Yes" : "No") << "\n";
    }
}

void RoomUI::addRoom() {
    Room room;
    std::cout << "Enter Room Type: ";
    std::cin >> room.type;
    std::cout << "Enter Room Price: ";
    std::cin >> room.price;
    room.isAvailable = true;

    roomManager->addRoom(room);
    std::cout << "Room added successfully.\n";
}

void RoomUI::removeRoom() {
    int roomId;
    std::cout << "Enter Room ID to remove: ";
    std::cin >> roomId;

    roomManager->removeRoom(roomId);
    std::cout << "Room removed successfully.\n";
}

void RoomUI::updateRoomStatus() {
    int roomId;
    bool isAvailable;
    std::cout << "Enter Room ID to update status: ";
    std::cin >> roomId;
    std::cout << "Enter availability (1 for Available, 0 for Not Available): ";
    std::cin >> isAvailable;

    roomManager->updateRoomStatus(roomId, isAvailable);
    std::cout << "Room status updated successfully.\n";
}
