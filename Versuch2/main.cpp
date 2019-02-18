#include <iostream>
#include<string>
#include <vector>
#include<fstream>

//letzte Zeile in .csv um einen Zeilenumbruch erweitert, sonst fehlt letzter Block
using namespace std;

class CSVData{
public:
    void pushToken(string token){
        this->ObjectToken.push_back(token);
    }
    void pushWert(string wert){
        this->ObjectTokenWert.push_back(wert);
    }
    string returnToken(int n){
        return this->ObjectToken[n];
    }
    string returnWert(int n){
        return this->ObjectTokenWert[n];
    }
    vector<string>ObjectToken;
    vector<string>ObjectTokenWert;
private:


protected:
};

int main(int argc, char** argv) {

    string buffer;
    char zeichen;
    int zustand=0;//0=Token, 1=Werte
    int iteratorStelle=0;
    vector<string>Token; //First line
    vector<string>::iterator TokenStelle;

    vector<string>::iterator TokenStelle2;


    class CSVData *ObjectPtr;
    CSVData Datensatz;
    ObjectPtr=&Datensatz;
    vector<CSVData>ObjectSave;
    vector<CSVData>:: iterator ObjectSaveIt;
    vector<CSVData*> ObjectPtrSave;
    vector<CSVData*>::iterator OPSiT;
    int OPSiTStelle=0;

    int y=0,z=0;


    ifstream eingabe;
    ofstream ausgabe;

    if(argc==1){
        //eingabe.open(argv[1]);
        cout<<"Kein cmdline-Input.Liest denkmalliste-bereinigt.csv: "<<endl;
        cout<<"Ergebnisse in: lib/Test.txt"<<endl;
        eingabe.open("../../denkmalliste-bereinigt.csv");
    }
    else if(argc>1){
        cout<<"Diese Datei wird geoeffnet: "<<argv[1]<<endl;
        cout<<"Ergebnisse in: ..lib/Test.txt"<<endl;
        eingabe.open(argv[1]);
    }

    ausgabe.open("../lib/Test.txt"); //ausgabe in externe Datei, da (mein) Clion Terminal nicht alles anzeigt

    if(eingabe) {
        for (;;) {
            if (eingabe.eof()) {
                break;
            }

            eingabe.get(zeichen);

            switch (zeichen) {
                case ';':
                    if (zustand == 0) {
                        Token.push_back(buffer);
                        //ausgabe << "Token: " << buffer << "; ";//<<flush;
                    }
                    else if (zustand == 1) {
                        ObjectPtr->pushWert(buffer);
                        //Werte.push_back(buffer);
                        //ausgabe << "Wert: " << buffer << "; ";//<<flush;
                    }
                    buffer = "";
                    break;
                case '\n':
                    if (zustand == 0) {
                        zustand = 1;
                        Token.push_back(buffer);
                        ObjectPtr=new CSVData; //ptr to new Object; (nur in erster Zeile)
                        //AllData.push_back(Token);
                        //ausgabe << "Token: " << buffer << endl;//<<flush;
                        //Token.clear();
                    } else if (zustand == 1) {
                       /* for(TokenStelle=Token.begin();TokenStelle!=Token.end();TokenStelle++,iteratorStelle++){
                            ObjectPtr->pushToken(Token[iteratorStelle]); //Geht durch TokenVector und schreibt jeden Wert in den TokenVector im Objekt
                        }*/
                        ObjectPtr->pushWert(buffer); //letzter Wert wird gespeichert
                        ObjectPtrSave.push_back(ObjectPtr); // Vektor wird um das Objekt erweitert, auf das ptr zeigt/ ODER um den Pointer??
                        ObjectSave.push_back(*ObjectPtr); //NEW******************************************
                        ObjectPtr=new CSVData;;//PTR auf neues Objekt
                        //llData.push_back(Werte);
                        //Werte.clear();
                        //ausgabe << "Wert: " << buffer << endl;//4<<flush;
                    }
                    buffer = "";
                    break;
                default:
                    buffer += zeichen;
                    break;
            }
        }
    }
    else{
        cout<<"file not found"<<endl;
    }

    for(ObjectSaveIt=ObjectSave.begin();ObjectSaveIt!=ObjectSave.end();++ObjectSaveIt){
        for (TokenStelle = Token.begin(); TokenStelle != Token.end(); ++TokenStelle) {
            ObjectPtr->pushToken(
                    Token[iteratorStelle]); //Geht durch TokenVector und schreibt jeden Wert in den TokenVector im Objekt
        }
        //ausgabe<<(*ObjectSaveIt).returnToken(2)<<endl;
    }
    /* for(OPSiT=ObjectPtrSave.begin();OPSiT!=ObjectPtrSave.end();++OPSiT) {
        for (TokenStelle = Token.begin(); TokenStelle != Token.end(); ++TokenStelle) {
            ObjectPtr->pushToken(Token[iteratorStelle]); //Geht durch TokenVector und schreibt jeden Wert in den TokenVector im Objekt
            //cout<<*TokenStelle<<endl;
        }
    }*/
   // for(OPSiT=ObjectPtrSave.begin();OPSiT!=ObjectPtrSave.end();OPSiT++, y++){
        //z=0;
     //   cout << ObjectPtrSave[y]->returnToken(1)<<": ";
        /*for(TokenStelle2=(*OPSiT)->ObjectToken.begin();TokenStelle2!=(*OPSiT)->ObjectToken.end();TokenStelle2++,z++){
            cout << ObjectPtrSave[y]->returnToken(z)<<": ";//ObjectPtrSave[y]->returnWert(z);
        }*/
    //cout<<endl;

   //}
    /*for(stelle1=AllData.begin();stelle1!=AllData.end();stelle1++){ // i beginnt bei 1, damit die Token nicht einmal allein ausgegeben werden
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
    }*/
    eingabe.close();

    return 0;
}