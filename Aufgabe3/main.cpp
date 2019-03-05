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
    ofstream Jsonausgabe;
    ausgabe.open("../lib/Test.txt"); //ausgabe in externe Datei, da (mein) Clion Terminal nicht alles anzeigt
    Jsonausgabe.open("../lib/JsonExport.json");

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
    //ausgabe in Json-Datei
    Jsonausgabe<<"{\"Liste\" : {"<<endl;
    for(APiT=AllPointer.begin();APiT!=AllPointer.end();APiT++){
        vector<Denkmal*>::iterator secondLast = AllPointer.end();
        advance(secondLast, -1); //sollte nun auf letztes Element im Vector zeigen
        Jsonausgabe<<"\t\"Datensatz\": {"<<endl;
        int y=0;
        int x=(*APiT)->getWertLength();
        for(y=0;y!=x;y++){
            if(y==0||y==2||y==3||y==4) { // abfangen von ints, die in Json kein "" haben. ->nicht mehr so agil....
                if((*APiT)->readWert(y)=="o.Nr."){
                    Jsonausgabe<<"\t\t\""<<(*APiT)->readToken(y)<<"\" "<<": "<<"\""<<(*APiT)->readWert(y)<<"\" "<<","<<endl;
                }
                else {
                    Jsonausgabe << "\t\t\"" << (*APiT)->readToken(y) << "\" " << ": " << (*APiT)->readWert(y) << ","
                                << endl;
                }
            }
            else if(y==x-1){
                Jsonausgabe<<"\t\t\""<<(*APiT)->readToken(y)<<"\" "<<": "<<"\""<<(*APiT)->readWert(y)<<"\" "<<endl; // Komma-removal last Element
            }
            else{
                Jsonausgabe<<"\t\t\""<<(*APiT)->readToken(y)<<"\" "<<": "<<"\""<<(*APiT)->readWert(y)<<"\" "<<","<<endl;
            }
        }
        if(distance(APiT,secondLast)==0){ //Komma-removal last Element
            Jsonausgabe<<"\t}"<<endl;
        }
        else{
                Jsonausgabe<<"\t},"<<endl;
                }
    }
    Jsonausgabe<<"}";



    eingabe.close();

    return 0;
}