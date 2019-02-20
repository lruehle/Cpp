#include <iostream>
#include<string>
#include <vector>
#include<fstream>
#include "lib/Denkmal.h"
//#include "lib/Denkmal.cpp"


using namespace std;

int main(int argc, char** argv) {

    string buffer;
    int zustand=0;//0=Token, 1=Werte

    Denkmal Datensatz;
    class Denkmal *ptr;
    ptr=&Datensatz;

    vector<Denkmal*> AllPointer;
    vector<Denkmal*>::iterator APiT;
    vector<string> Token;
    vector<string>::iterator stelle2;
    vector<string> Werte;
    vector<vector<string>> AllData;


    ifstream eingabe;
    ofstream ausgabe;
    ausgabe.open("../lib/Test.txt"); //ausgabe in externe Datei, da (mein) Clion Terminal nicht alles anzeigt

    if(argc==1){
        cout<<"liest ../denkmalliste-bereinigt.csv: "<<endl;
        cout<<"Ergebnisse in: lib/Test.txt"<<endl;
        eingabe.open("../../denkmalliste-bereinigt.csv");
    }
    else if(argc>1){
        cout<<"Diese Datei wird geoeffnet: "<<argv[1]<<endl;
        cout<<"Ergebnisse in: ..lib/Test.txt"<<endl;
        eingabe.open(argv[1]);
    }

    if(eingabe) {
        for (;;) {
            if (eingabe.eof()) {
                break;
            }
            if(zustand==0){
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Token.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,'\n');
                Token.push_back(buffer);
                buffer="";
                zustand=1;
            }
            else if(zustand==1){
                ptr= new Denkmal();
                for(stelle2=Token.begin();stelle2!=Token.end();stelle2++){
                    ptr->pushBack_Token(*stelle2);
                }
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,';');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                getline(eingabe,buffer,'\n');
                ptr->pushBack_Wert(buffer);
                buffer="\n";
                AllPointer.push_back(ptr);
                zustand=1;
            }
        }
    }
    else{
        cout<<"file not found"<<endl;
    }
    for(APiT=AllPointer.begin();APiT!=AllPointer.end();APiT++){
        int y=0;
        int x=(*APiT)->getWertLength();
        for(y=0;y!=x;y++){
            ausgabe<<(*APiT)->readToken(y)<<": "<<(*APiT)->readWert(y)<<"; "<<endl;
        }
        ausgabe<<endl;
    }

    eingabe.close();

    return 0;
}