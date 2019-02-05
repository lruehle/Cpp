#include <iostream>
#include<string>
#include <vector>
#include<fstream>

//letzte Zeile in .csv um einen Zeilenumbruch erweitert, sonst fehlt letzter Block
using namespace std;

int main() {

    string buffer;
    char zeichen;
    vector<string>Token;
    vector<string>Werte;
    vector<vector<string>>AllData;
    vector<vector<string>>::iterator stelle1; //AllData[stelle1][stelle2]; ->Spalten
    vector<string>::iterator stelle2; //Zeilen


    ifstream eingabe;
    ofstream ausgabe;
    eingabe.open("../../denkmalliste-bereinigt.csv");
    //eingabe.open("../lib/Daten.txt");
    ausgabe.open("../lib/Test.txt"); //ausgabe in externe Datei, da (mein) Clion Terminal nicht alles anzeigt

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
                        Token.push_back(buffer);
                        //ausgabe << "Token: " << buffer << "; ";//<<flush;
                    } else if (zustand == 1) {
                        Werte.push_back(buffer);
                        //ausgabe << "Wert: " << buffer << "; ";//<<flush;
                    }
                    buffer = "";
                    break;
                case '\n':
                    if (zustand == 0) {
                        zustand = 1;
                        Token.push_back(buffer);
                        AllData.push_back(Token);
                        //ausgabe << "Token: " << buffer << endl;//<<flush;
                        Token.clear();
                    } else if (zustand == 1) {
                        Werte.push_back(buffer);
                        AllData.push_back(Werte);
                        Werte.clear();
                        //ausgabe << "Wert: " << buffer << endl;//4<<flush;
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


    /*for(int i=1;i<=8778;i++){ // i beginnt bei 1, damit die Token nicht einmal allein ausgegeben werden
        int y=0; // Damit immer nur die Token ausgegeben werden -> Stehen an AllData[0][n];
        for(stelle2=AllData[i].begin();stelle2!=AllData[i].end();stelle2++){
             ausgabe<<AllData[0][y]<<": "; // für die Ausgabe der Token;
             ausgabe<<(*stelle2)<<endl;
             y++;
        }
        ausgabe<<"\n";
        //ausgabe<<AllData[i][0]<<endl;
    }*/
    for(stelle1=AllData.begin();stelle1!=AllData.end();stelle1++){ // i beginnt bei 1, damit die Token nicht einmal allein ausgegeben werden
        int y=0; // Damit immer nur die Token ausgegeben werden -> Stehen an AllData[0][n];
        if (stelle1==AllData.begin()){
            //kick out Block mit ausschließlich Tocken
        }
        else{
            for(stelle2=(*stelle1).begin();stelle2!=(*stelle1).end();stelle2++){
                ausgabe<<AllData[0][y]<<": "; // für die Ausgabe der Token;
                ausgabe<<(*stelle2)<<endl;
                y++;
            }
        }
        ausgabe<<"\n";
        //ausgabe<<AllData[i][0]<<endl;
    }
    eingabe.close();

    return 0;
}