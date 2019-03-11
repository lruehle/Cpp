//
// Created by lilly on 09.03.2019.
//

#ifndef AUFGABE4CLEAN_DENKMAL_H
#define AUFGABE4CLEAN_DENKMAL_H

#endif //AUFGABE4CLEAN_DENKMAL_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Denkmal{
private:
    vector<string>ObjectToken;
    vector<string>ObjectWert;
public:
    Denkmal();
    ~Denkmal();
    void pushBack_Token(string Token);
    void pushBack_Wert(string Wert);
    string WritetoJson(int i);
    string printAllData();
    string readToken(int y);
    string readWert(int y);
    bool checkPLZ(string);
    int getWertLength();
protected:
};
