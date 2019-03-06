//
// Created by lilly on 06.03.2019.
//

#ifndef AUFGABE4_DENKMAL_H
#define AUFGABE4_DENKMAL_H

#endif //AUFGABE4_DENKMAL_H


#include <string>
#include <vector>
using namespace std;

class Denkmal{
private:
    vector<string>ObjectToken;
    vector<string>ObjectWert;
public:
    Denkmal();
    void pushBack_Token(string Token);
    void pushBack_Wert(string Wert);
    string WritetoJson();
    string printAllData();
    string readToken(int y);
    string readWert(int y);
    bool checkPLZ(string);
    int getWertLength();
protected:
};
