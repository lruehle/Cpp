    //
// Created by lilly on 20.02.2019.
//

#ifndef AUFGABE2_CLEAN_DENKMAL_H
#define AUFGABE2_CLEAN_DENKMAL_H
#endif //AUFGABE2_CLEAN_DENKMAL_H

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
        string readToken(int y); //Says is never used, but is used??
        string readWert(int y);
        int getWertLength();
    protected:
    };
