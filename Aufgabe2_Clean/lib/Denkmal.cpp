//
// Created by lilly on 20.02.2019.
//
#include "Denkmal.h"
using namespace std;

Denkmal::Denkmal(){
    ObjectToken.clear(); //constr

}
void Denkmal::pushBack_Token(string Token){
    this->ObjectToken.push_back(Token);
}
void Denkmal::pushBack_Wert(string Wert){
    this->ObjectWert.push_back(Wert);
}
string Denkmal::readToken(int y){
    return this->ObjectToken[y];
}
string Denkmal::readWert(int y){
    return this->ObjectWert[y];
}
int Denkmal::getWertLength(){
    return this->ObjectWert.size();
}