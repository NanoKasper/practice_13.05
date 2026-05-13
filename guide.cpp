#include "guide.h"
#include <iostream>

using namespace std;

Guide::Guide(string n) {
    name = n;
    currentRoom = nullptr;
}

void Guide::goToRoom(Room* room, int groupSize) {
    if (room == nullptr) return;
    
    // Доп задание: запрет посещения серверной, если группа слишком большая
    if (room->getName() == "Серверная" && groupSize > room->getCapacity()) {
        cout << "\nГруппа из " << groupSize 
             << " человек не может посетить серверную!" << endl;
        cout << "Максимальная вместимость серверной: " << room->getCapacity() 
             << " человек." << endl;
        cout << "Пожалуйста, выберите другую комнату.\n" << endl;
        return;
    }
    
    currentRoom = room;
    currentRoom->visit();
    cout << "\nГид " << name << " провёл группу в комнату: " 
         << currentRoom->getName() << endl;
    
    // Доп задание: предупреждение о вместимости
    if (groupSize > currentRoom->getCapacity() && currentRoom->getName() != "Серверная") {
        cout << "Предупреждение: Группа из " << groupSize 
             << " человек превышает вместимость комнаты (" 
             << currentRoom->getCapacity() << " человек)!" << endl;
    }
}

void Guide::printCurrentRoomInfo() {
    if (currentRoom != nullptr) {
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
    } else {
        cout << "Группа пока не находится ни в одной комнате." << endl;
    }
}

//вывод информации о гиде
void Guide::printGuideInfo() {
    cout << "Информация о гиде:" << endl;
    cout << "Имя: " << name << endl;
    if (currentRoom != nullptr) {
        cout << "Текущая локация: " << currentRoom->getName() << endl;
    } else {
        cout << "Текущая локация: экскурсия ещё не началась" << endl;
    }
}

Room* Guide::getCurrentRoom() {
    return currentRoom;
}

string Guide::getName() {
    return name;
}