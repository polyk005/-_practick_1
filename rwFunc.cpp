#include "rwFunc.hpp"
#include <iostream>
#include <sstream>

bool readFromFile(const string& filename, vector<GardenMember>& members) {
    ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла для чтения: " << filename << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        GardenMember member;

        // Чтение ID
        getline(ss, token, ';');
        member.id = stoi(token);

        // Чтение номера участка
        getline(ss, token, ';');
        member.plotNumber = stoi(token);

        // Чтение ФИО
        getline(ss, member.fullName, ';');

        // Чтение номера телефона
        getline(ss, member.phoneNumber, ';');

        // Чтение адреса
        getline(ss, member.address, ';');

        members.push_back(member);
    }

    inputFile.close();
    return true;
}

bool writeToFile(const string& filename, const vector<GardenMember>& members) {
    ofstream outputFile(filename);
    
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла для записи: " << filename << endl;
        return false;
    }

    for (const auto& member : members) {
        outputFile << member.id << ";"
                   << member.plotNumber << ";"
                   << member.fullName << ";"
                   << member.phoneNumber << ";"
                   << member.address << ";\n";
    }

    outputFile.close();
    return true;
}