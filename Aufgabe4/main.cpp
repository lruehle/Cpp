#include <iostream>
#include<string>
#include <vector>
#include<fstream>
#include "lib/Denkmal.h"
//#include "lib/Denkmal.cpp"


using namespace std;

int main(int argc, char** argv) {

    string buffer;
    string Usereingabe;
    int zustand = 0;//0=Token, 1=Werte

    Denkmal Datensatz;
    class Denkmal *ptr;
    ptr = &Datensatz;

    vector<Denkmal *> AllPointer;
    vector<Denkmal *>::iterator APiT;
    vector<string> Token;
    vector<string>::iterator stelle2;
    vector<string> Werte;
    vector<vector<string>> AllData;

    ifstream eingabe;
    ofstream ausgabe;
    ofstream Jsonausgabe;
    ofstream PLZAusgabe;
    ausgabe.open("../lib/Test.txt"); //ausgabe in externe Datei, da (mein) Clion Terminal nicht alles anzeigt
    Jsonausgabe.open("../lib/JsonExport.json");
    PLZAusgabe.open("../lib/PLZAusgabe.txt");

    if (argc == 1) {
        cout << "liest ../denkmalliste-bereinigt.csv: " << endl;
        cout << "*** Ergebnisse in: lib/Test.txt ***" << endl;
        eingabe.open("../../denkmalliste-bereinigt.csv");
    } else if (argc > 1) {
        cout << "Diese Datei wird geoeffnet: " << argv[1] << endl;
        cout << "Ergebnisse in: ..lib/Test.txt" << endl;
        eingabe.open(argv[1]);
    }

    if (eingabe) {
        for (;;) {
            if (eingabe.eof()) {
                break;
            }
            if (zustand == 0) {
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, ';');
                Token.push_back(buffer);
                buffer = "";
                getline(eingabe, buffer, '\n');
                Token.push_back(buffer);
                buffer = "";
                zustand = 1;
            } else if (zustand == 1) {
                ptr = new Denkmal();
                for (stelle2 = Token.begin(); stelle2 != Token.end(); stelle2++) {
                    ptr->pushBack_Token(*stelle2);
                }
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, ';');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                getline(eingabe, buffer, '\n');
                ptr->pushBack_Wert(buffer);
                buffer = "\n";
                AllPointer.push_back(ptr);
                zustand = 1;
            }
        }
    } else {
        cout << "file not found" << endl;
    }
    for (APiT = AllPointer.begin(); APiT != AllPointer.end(); APiT++) {
        ausgabe << (*APiT)->printAllData() << endl;
    }

    //ausgabe in Json-Datei
    Jsonausgabe << "{\"Liste\" : {" << endl;
    for (APiT = AllPointer.begin(); APiT != AllPointer.end(); APiT++) {
        vector<Denkmal *>::iterator secondLast = AllPointer.end();
        advance(secondLast, -1); //sollte nun auf letztes Element im Vector zeigen
        Jsonausgabe << (*APiT)->WritetoJson();

        if (distance(APiT, secondLast) == 0) { //Komma-removal last Element
            Jsonausgabe << "\t}" << endl;
        } else {
            Jsonausgabe << "\t}," << endl;
        }
    }
    Jsonausgabe << "}";
    cout << "*** JsonErgebnisse in lib/JsonExport.json ***" << endl;

    //PLZ Abfrage
    int wdh=1;
    while (wdh != 0){
        cout << "Datensaetze mit welcher Postleizahl ausgeben?" << endl;
        cin >> Usereingabe;
        if (Usereingabe.length() >= 6) {
            cout << "Zu lang für eine PLZ, bitt nur 5 Stellen eingeben" << endl;
        }
            //else if(all_of(Usereingabe.begin(),Usereingabe.end(),::isdigit())){
        else if (Usereingabe.find_first_not_of("0123456789") != string::npos) { //compares to "notFound"
            cout << "Bitte nur Zahlen eingeben!" << endl;
        }
        else {
            wdh=0;
            int count=0;
            cout << "Suche nach " << Usereingabe << " " << endl;
            for (APiT = AllPointer.begin(); APiT != AllPointer.end(); APiT++) {
                if ((*APiT)->checkPLZ(Usereingabe)) {
                    count++;
                    PLZAusgabe << (*APiT)->printAllData() << endl;
                }
            }
            if(count==0){
                cout<<"Keine Datensaetze mit dieser PLZ in Datei"<<endl;
            }
        }
    }
    eingabe.close();

    return 0;
}