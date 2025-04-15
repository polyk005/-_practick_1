#include "menu.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void displayMembers(const vector<GardenMember>& members) {
    cout << "\nСписок членов садового товарищества:\n";
    cout << "------------------------------------------------------------\n";
    cout << "ID | Участок | ФИО владельца       | Телефон    | Адрес\n";
    cout << "------------------------------------------------------------\n";
    
    for (const auto& member : members) {
        cout << setw(2) << member.id << " | "
             << setw(7) << member.plotNumber << " | "
             << setw(19) << member.fullName << " | "
             << setw(10) << member.phoneNumber << " | "
             << member.address << endl;
    }
    cout << "------------------------------------------------------------\n";
}

void aboutProgram() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    cout << "\nИнформация о программе:\n";
    cout << "-----------------------\n";
    cout << "Автор: Поляков Кирилл Дмитриевич\n";
    cout << "Курс: 2\n";
    cout << "Группа: 2\n";
    cout << "Вариант: Садовое товарищество\n";
    cout << "Дата компиляции: " 
         << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday << " "
         << ltm->tm_hour << ":"
         << ltm->tm_min << ":"
         << ltm->tm_sec << "\n";
    cout << "-----------------------\n";
}

void menu() {
    vector<GardenMember> members;
    string filename = "gardenassociat.db";
    int choice;
    
    do {
        cout << "\nМеню:\n";
        cout << "1. Открыть файл\n";
        cout << "2. Сохранить файл\n";
        cout << "3. Вывести на экран список\n";
        cout << "4. О программе\n";
        cout << "5. Выход\n";
        cout << "Выберите пункт меню: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера
        
        switch (choice) {
            case 1:
                if (readFromFile(filename, members)) {
                    cout << "Файл успешно загружен!\n";
                }
                break;
            case 2:
                if (writeToFile(filename, members)) {
                    cout << "Файл успешно сохранен!\n";
                }
                break;
            case 3:
                if (!members.empty()) {
                    displayMembers(members);
                } else {
                    cout << "Список пуст. Сначала загрузите данные из файла.\n";
                }
                break;
            case 4:
                aboutProgram();
                break;
            case 5:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);
}