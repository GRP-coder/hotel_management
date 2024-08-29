#include "Room.h"

Room::Room() : id(0), type(""), price(0.0), isAvailable(true) {}

Room::Room(int id, const std::string& type, double price, bool isAvailable)
    : id(id), type(type), price(price), isAvailable(isAvailable) {}
