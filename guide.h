#ifndef GUIDE_H
#define GUIDE_H

#include <string>
#include "room.h"

using namespace std;

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(string n);
    void goToRoom(Room* room, int groupSize = 0); 
    void printCurrentRoomInfo();
    void printGuideInfo();
    Room* getCurrentRoom();
    string getName();
};

#endif // GUIDE_H