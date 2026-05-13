#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    Room(string n, string t, int cap) {
        name = n;
        type = t;
        capacity = cap;
        visitCount = 0;
    }

    void printInfo() {
        cout << "Название: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Количество посещений: " << visitCount << endl;
    }

    void visit() {
        visitCount++;
    }

    int getVisitCount() {
        return visitCount;
    }

    string getName() {
        return name;
    }

    string getType() {
        return type;
    }

    int getCapacity() {
        return capacity;
    }
};

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(string n) {
        name = n;
        currentRoom = nullptr;
    }

    void goToRoom(Room* room) {
        if (room != nullptr) {
            currentRoom = room;
            currentRoom->visit();
            cout << "Гид " << name << " провёл группу в комнату: " 
                 << currentRoom->getName() << endl;
        }
    }

    void printCurrentRoomInfo() {
        if (currentRoom != nullptr) {
            cout << "Текущая комната:" << endl;
            currentRoom->printInfo();
        } else {
            cout << "Группа пока не находится ни в одной комнате." << endl;
        }
    }

    //указатель на текущую комнату
    Room* getCurrentRoom() {
        return currentRoom;
    }

    //имя гида
    string getName() {
        return name;
    }
};

//меню
void printMenu() {
    cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
    cout << "1. Посетить комнату" << endl;
    cout << "2. Информация о текущей комнате" << endl;
    cout << "3. Показать все посещённые комнаты" << endl;
    cout << "4. Самая посещаемая комната" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите пункт: ";
}

//список доступных комнат
void printAvailableRooms(Room* rooms[], int count) {
    cout << "\nДоступные комнаты:" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

//посещённые комнаты
void showVisitedRooms(Room* rooms[], int count) {
    bool hasVisited = false;
    cout << "\nПосещённые комнаты:" << endl;
    
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            cout << rooms[i]->getName() << " — " 
                 << rooms[i]->getVisitCount() << " посещений" << endl;
            hasVisited = true;
        }
    }
    
    if (!hasVisited) {
        cout << "Пока не посещено ни одной комнаты." << endl;
    }
}

//самая посещаемая комната
void showMostVisitedRoom(Room* rooms[], int count) {
    int maxVisits = -1;
    int mostVisitedIndex = -1;
    
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > maxVisits) {
            maxVisits = rooms[i]->getVisitCount();
            mostVisitedIndex = i;
        }
    }
    
    if (mostVisitedIndex != -1 && maxVisits > 0) {
        cout << "\nСамая посещаемая комната: " 
             << rooms[mostVisitedIndex]->getName() << endl;
        cout << "Количество посещений: " << maxVisits << endl;
    } else {
        cout << "\nПока нет посещённых комнат." << endl;
    }
}

int main() {
    Room* rooms[5];
    
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);
    
    Guide guide("Иван");
    
    int choice;
    bool running = true;
    
    while (running) {
        printMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: { // Посетить комнату
                printAvailableRooms(rooms, 5);
                int roomNumber;
                cout << "Введите номер комнаты: ";
                cin >> roomNumber;
                
                if (roomNumber >= 1 && roomNumber <= 5) {
                    guide.goToRoom(rooms[roomNumber - 1]);
                } else {
                    cout << "Неверный номер комнаты!" << endl;
                }
                break;
            }
            
            case 2: { // Информация о текущей комнате
                guide.printCurrentRoomInfo();
                break;
            }
            
            case 3: { // Показать все посещённые комнаты
                showVisitedRooms(rooms, 5);
                break;
            }
            
            case 4: { // Самая посещаемая комната
                showMostVisitedRoom(rooms, 5);
                break;
            }
            
            case 5: { // Выход
                cout << "Завершение программы..." << endl;
                running = false;
                break;
            }
            
            default: {
                cout << "Неверный пункт меню! Попробуйте снова." << endl;
                break;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }
    
    cout << "Программа завершена." << endl;
    
    return 0;
}