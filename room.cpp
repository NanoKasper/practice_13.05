#include "room.h"
#include <iostream>

using namespace std;

Room::Room(string n, string t, int cap) {
    name = n;
    type = t;
    capacity = cap;
    visitCount = 0;
}

void Room::printInfo() {
    cout << "Название: " << name << endl;
    cout << "Тип: " << type << endl;
    cout << "Вместимость: " << capacity << endl;
    cout << "Количество посещений: " << visitCount << endl;
}

void Room::visit() {
    visitCount++;
}

int Room::getVisitCount() {
    return visitCount;
}

string Room::getName() {
    return name;
}

string Room::getType() {
    return type;
}

int Room::getCapacity() {
    return capacity;
}