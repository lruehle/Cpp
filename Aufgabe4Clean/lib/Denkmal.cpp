//
// Created by lilly on 06.03.2019.
//

#include "Denkmal.h"
using namespace std;

Denkmal::Denkmal(){
    ObjectToken.clear(); //constr
}
Denkmal::~Denkmal(){

}
void Denkmal::pushBack_Wert(string Wert){
    this->ObjectWert.push_back(Wert);
}

string Denkmal::WritetoJson(int count) {
    string ausgabe;
    int y=0;
    int x=this->getWertLength();
    string stringcount=to_string(count);
    ausgabe+="\t\"Datensatz "+stringcount+"\": {\n";

    for(y=0;y!=x;y++){
        string s1=this->readWert(y);
        string s2="-";
        string s3="\"";

        if(y!=x-1) {
            if(s1.find_first_not_of("0123456789") == string::npos){ //gilt auch für empties
                if(s1.empty()){
                    ausgabe+="\t\t\""+this->readToken(y)+"\" : \"\", \n";
                }
                else{
                    ausgabe += "\t\t\"" + this->readToken(y) + "\" : " + this->readWert(y) + ", \n";
                }

            }
            else{
                ausgabe+="\t\t\""+this->readToken(y)+"\" : \""+this->readWert(y)+"\" , \n";
            }
        }

        else if(y==x-1){
            if(s1.find(s3)!=string::npos){  //  filter fuer"" z.B Nr. 8696 ("Siedlung ""Weiße Stadt""") (https://thispointer.com/how-to-remove-substrings-from-a-string-in-c/)
                size_t pos=string::npos;
                while((pos=s1.find(s3))!=string::npos){
                    //s1.erase(pos,s3.length());
                    replace(s1.begin(),s1.end(),'\"','\'');
                }
                ausgabe+="\t\t\""+this->readToken(y)+"\" : \""+s1+"\" \n";
            }
            else{
                ausgabe+="\t\t\""+this->readToken(y)+"\" : \""+this->readWert(y)+"\" \n";
            }
        }
    }
    return ausgabe;
}

string Denkmal::printAllData() {
    string DataAusgabe;
    int y=0;
    int x=this->getWertLength();
    for(y=0;y!=x;y++){
        DataAusgabe+=this->readToken(y)+": "+this->readWert(y)+"; \n";
    }
    return DataAusgabe;
}
string Denkmal::readToken(int y){
    return this->ObjectToken[y];
}
string Denkmal::readWert(int y){
    return this->ObjectWert[y];
}

bool Denkmal::checkPLZ(string Usereingabe){
    if(Usereingabe.compare(this->readWert(4))==0){
        return true;
    }
    else{
        return false;
    }

}

int Denkmal::getWertLength(){
    return this->ObjectWert.size();
}
