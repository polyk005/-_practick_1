#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct GardenMember {
    int id;
    int plotNumber;
    string fullName;
    string phoneNumber;
    string address;
};

bool readFromFile(const string& filename, vector<GardenMember>& members);
bool writeToFile(const string& filename, const vector<GardenMember>& members);

#endif