#include <iostream>
#include <string>

class Room {
public:
    std::string description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;

    Room(std::string desc) : description(desc), north(nullptr), south(nullptr), east(nullptr), west(nullptr) {}
};

void describeRoom(Room* room) {
    std::cout << room->description << std::endl;
    if (room->north) std::cout << "There is a door to the north." << std::endl;
    if (room->south) std::cout << "There is a door to the south." << std::endl;
    if (room->east) std::cout << "There is a door to the east." << std::endl;
    if (room->west) std::cout << "There is a door to the west." << std::endl;
}

int main() {
    Room* livingRoom = new Room("You are in a cozy living room. There is a fireplace here.");
    Room* kitchen = new Room("You are in a kitchen. There are pots and pans everywhere.");
    Room* bedroom = new Room("You are in a bedroom. There is a large bed here.");
    Room* bathroom = new Room("You are in a bathroom. There is a shower and a sink.");

    livingRoom->north = kitchen;
    kitchen->south = livingRoom;
    kitchen->east = bedroom;
    bedroom->west = kitchen;
    bedroom->south = bathroom;
    bathroom->north = bedroom;

    Room* currentRoom = livingRoom;
    std::string command;

    std::cout << "Welcome to the Text Adventure Game!" << std::endl;

    while (true) {
        describeRoom(currentRoom);
        std::cout << "Enter a command (north, south, east, west, quit): ";
        std::cin >> command;

        if (command == "north" && currentRoom->north) {
            currentRoom = currentRoom->north;
        } else if (command == "south" && currentRoom->south) {
            currentRoom = currentRoom->south;
        } else if (command == "east" && currentRoom->east) {
            currentRoom = currentRoom->east;
        } else if (command == "west" && currentRoom->west) {
            currentRoom = currentRoom->west;
        } else if (command == "quit") {
            std::cout << "Thanks for playing!" << std::endl;
            break;
        } else {
            std::cout << "You can't go that way." << std::endl;
        }
    }

    delete livingRoom;
    delete kitchen;
    delete bedroom;
    delete bathroom;

    return 0;
}

