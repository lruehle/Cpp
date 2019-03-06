//
// Created by lilly on 06.03.2019.
//

#ifndef AUFGABE3B_DENKMAL_H
#define AUFGABE3B_DENKMAL_H

#endif //AUFGABE3B_DENKMAL_H

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
    string readToken(int y);
    string readWert(int y);
    int getWertLength();
protected:
};
