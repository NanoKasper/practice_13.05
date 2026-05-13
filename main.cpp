#include <iostream>
#include "room.h"
#include "guide.h"

using namespace std;

//меню
void printMenu() {
    cout << "======= Экскурсия по офису Яндекса" << endl;
    cout << "1. Посетить комнату" << endl;
    cout << "2. Информация о текущей комнате" << endl;
    cout << "3. Показать все посещённые комнаты" << endl;
    cout << "4. Самая посещаемая комната" << endl;
    cout << "5. Информация о гиде" << endl;
    cout << "6. Показать список всех комнат" << endl;
    cout << "7. Выход" << endl;
    cout << "Выберите пункт: ";
}

//список доступных комнат
void printAvailableRooms(Room* rooms[], int count) {
    cout << "\nДоступные комнаты:" << endl;
    cout << "Номер - Название - Тип - Вместимость" << endl;
    for (int i = 0; i < count; i++) {
        printf(" %1d - %1s - %1s - %1d \n", 
               i + 1, 
               rooms[i]->getName().c_str(), 
               rooms[i]->getType().c_str(), 
               rooms[i]->getCapacity());
    }
}

//вывод всех посещённых комнат
void showVisitedRooms(Room* rooms[], int count) {
    bool hasVisited = false;
    cout << "\nПосещённые комнаты:" << endl;
    cout << "Название - Тип - Количество посещений" << endl;
    
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            printf(" %1s - %1s - %1d \n", 
                   rooms[i]->getName().c_str(), 
                   rooms[i]->getType().c_str(), 
                   rooms[i]->getVisitCount());
            hasVisited = true;
        }
    }
    
    if (!hasVisited) {
        cout << "Пока не посещено ни одной комнаты" << endl;
    }
}

//поиск самой посещаемой комнаты
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
        cout << "Самая посещаемая комната" << endl;
        printf("Название: %1s\n", rooms[mostVisitedIndex]->getName().c_str());
        printf("Посещений: %1d\n", maxVisits);
    } else {
        cout << "\nПока нет посещённых комнат." << endl;
    }
}

//список всех комнат
void showAllRooms(Room* rooms[], int count) {
    cout << "\n список всех комнат:" << endl;
    cout << "Номер - Название - Тип - Вместимость - Посещений" << endl;
    
    for (int i = 0; i < count; i++) {
        printf(" %1d - %1s - %1s - %1d - %1d \n", 
               i + 1,
               rooms[i]->getName().c_str(), 
               rooms[i]->getType().c_str(), 
               rooms[i]->getCapacity(),
               rooms[i]->getVisitCount());
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
    int groupSize = 0;
    bool running = true;
    
    cout << "\n Добро пожаловать на экскурсию в Яндекс!" << endl;
    cout << "Вас встречает гид " << guide.getName() << endl;
    
    // Запрос размера группы
    cout << "\nВведите размер вашей группы: ";
    cin >> groupSize;
    if (groupSize <= 0) groupSize = 1;
    
    cout << "\n Экскурсия началась! Размер группы: " << groupSize << " человек\n";
    
    while (running) {
        printMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: { // Посетить комнату
                printAvailableRooms(rooms, 5);
                int roomNumber;
                cout << "\nВведите номер комнаты: ";
                cin >> roomNumber;
                
                if (roomNumber >= 1 && roomNumber <= 5) {
                    guide.goToRoom(rooms[roomNumber - 1], groupSize);
                } else {
                    cout << "Неверный номер комнаты!" << endl;
                }
                break;
            }
            
            case 2: { // Информация о текущей комнате
                cout << endl;
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
            
            case 5: { // Информация о гиде
                cout << endl;
                guide.printGuideInfo();
                break;
            }
            
            case 6: { // Список всех комнат
                showAllRooms(rooms, 5);
                break;
            }
            
            case 7: { // Выход
                cout << "\n Завершение программы..." << endl;
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
    
    cout << "\nПрограмма завершена. Спасибо за экскурсию!" << endl;
    
    return 0;
}