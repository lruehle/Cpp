#include <iostream>
#include<string>
#include <vector>
#include<fstream>

using namespace std;

int main() {

    string buffer;
    char zeichen;
    ifstream eingabe;
    ofstream ausgabe;
    eingabe.open("../../denkmalliste-bereinigt.csv");
    //eingabe.open("../lib/Daten.txt");
    ausgabe.open("../lib/Test.txt");

    int zustand=0;//0=Token, 1=Werte


    if(eingabe) {
        for (;;) {
            if (eingabe.eof()) {
                break;
            }
            eingabe.get(zeichen);
            //cout<<zeichen;
            switch (zeichen) {
                case ';':
                    if (zustand == 0) {
                        ausgabe << "Token: " << buffer << "; ";//<<flush;
                    } else if (zustand == 1) {
                        ausgabe << "Wert: " << buffer << "; ";//<<flush;
                    }
                    buffer = "";
                    break;
                case '\n':
                    if (zustand == 0) {
                        zustand = 1;
                        ausgabe << "Token: " << buffer << endl;//<<flush;
                    } else if (zustand == 1) {
                        ausgabe << "Wert: " << buffer << endl;//4<<flush;
                    }
                    buffer = "";
                    break;
                default:
                    buffer += zeichen;
                    break;
            }//blabla
            //cout<<"found"<<endl;


        }
    }
    else{
        cout<<"file not found"<<endl;
    }

    eingabe.close();

    return 0;
}