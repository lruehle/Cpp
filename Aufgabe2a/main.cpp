#include <iostream>
#include<string>
#include <vector>
#include<fstream>

//letzte Zeile in .csv um einen Zeilenumbruch erweitert, sonst fehlt letzter Block
using namespace std;
class CSVData{
private:

public:
    string w1, w2, w3,w4, w5,w6,w7,w8,w9,w10;
    string t1;string t2;string t3;string t4;string t5;string t6;string t7;string t8;string t9;string t10;
protected:
};
int main(int argc, char** argv) {

    string buffer;
    int zustand=0;//0=Token, 1=Werte

    CSVData Datensatz;
    class CSVData *ptr;
    ptr=&Datensatz;

    vector<string> Token;
    vector<string>::iterator stelle2;
    vector<string> Werte;
    vector<vector<string>> AllData;
    vector<vector<string>>::iterator stelle1;


    ifstream eingabe;
    ofstream ausgabe;
    ausgabe.open("../lib/Test.txt"); //ausgabe in externe Datei, da (mein) Clion Terminal nicht alles anzeigt

    if(argc==1){
        //eingabe.open(argv[1]);
        cout<<"liest denkmalliste-bereinigt.csv: "<<endl;
        cout<<"Ergebnisse in: lib/Test.txt"<<endl;
        eingabe.open("../../denkmalliste-bereinigt.csv");
    }
    else if(argc>1){
        cout<<"Diese Datei wird geoeffnet: "<<argv[1]<<endl;
        cout<<"Ergebnisse in: ..lib/Test.txt"<<endl;
        eingabe.open(argv[1]);
    }

    //eingabe.open("../lib/Daten.txt");



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
                /*getline(eingabe,Token[1],';');
                getline(eingabe,Token[2],';'); *******Was ist hier falsch??******
                getline(eingabe,Token[3],';');
                getline(eingabe,Token[4],';');
                getline(eingabe,Token[5],';');
                getline(eingabe,Token[6],';');
                getline(eingabe,Token[7],';');
                getline(eingabe,Token[8],';');
                getline(eingabe,Token[9],'\n');*/
                AllData.push_back(Token);
                zustand=1;
            }
            else if(zustand==1){
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,';');
                Werte.push_back(buffer);
                buffer="";
                getline(eingabe,buffer,'\n');
                Werte.push_back(buffer);
                buffer="";
                AllData.push_back(Werte);
                Werte.clear();
                zustand=1;
                /*getline(eingabe,Werte[0],';');
                getline(eingabe,Werte[1],';');
                getline(eingabe,Werte[2],';');
                getline(eingabe,Werte[3],';');
                getline(eingabe,Werte[4],';');
                getline(eingabe,Werte[5],';');
                getline(eingabe,Werte[6],';');
                getline(eingabe,Werte[7],';');
                getline(eingabe,Werte[8],';');
                getline(eingabe,Werte[9],'\n');*/
                /*AllData.push_back(Werte);
                Werte.clear();
                zustand=1;*/
            }
        }
    }
    else{
        cout<<"file not found"<<endl;
    }

    for(stelle1=AllData.begin();stelle1!=AllData.end();stelle1++){
        int y=0;
        if(stelle1==AllData.begin()){

        }
        else {
            for (stelle2 = (*stelle1).begin(); stelle2 != (*stelle1).end(); stelle2++) {
                ausgabe << AllData[0][y] << ": ";
                ausgabe << *stelle2 << endl;
                y++;
            }
        }
        ausgabe<<endl;
    }

    eingabe.close();

    return 0;
}