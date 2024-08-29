#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
public:
    int id;
    std::string type;
    double price;
    bool isAvailable;

    Room();
    Room(int id, const std::string& type, double price, bool isAvailable);
};

#endif // ROOM_H
