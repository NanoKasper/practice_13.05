#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    Room(string n, string t, int cap);

    void printInfo();
    void visit();
    int getVisitCount();
    string getName();
    string getType();
    int getCapacity();
};

#endif // ROOM_H