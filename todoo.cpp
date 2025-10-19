#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cstdlib>
#include<chrono>
#include<thread>
using namespace std;

#ifdef _WIN32
void pulisci(){
    system("cls");
}
#else
void pulisci(){
    system("clear");
}
#endif
////////////////////////////////////////////////
void uscita(){
    cout<<"uscita dal programma..."<<endl;
    exit(0);
}
////////////////////////////////////////////////
void dormi(){
    this_thread::sleep_for(chrono::seconds(1));
}
////////////////////////////////////////////////
void count(){
    cout<<"3..."<<endl;
    dormi();
    pulisci();
    cout<<"2..."<<endl;
    dormi();
    pulisci();
    cout<<"1..."<<endl;
    dormi();
    pulisci();
}
/////////////////////////////////////////////////
void titolo(){
    cout<<"=========================TO DO LIST====================================="<<endl;
}
/////////////////////////////////////////////////           start main
int main(){
    string q;
    int scelta = 0, t = 0, d = 0;
    string utente, f;
    vector <string> todo;

    titolo();
    cout<<"             inserisci nome utente: ";
        cin>>utente;
        if(utente!="stefan" && utente!="nadia"){//              riconoscimento utente
            cout<<"nome utente non riconosciuto"<<endl;
            uscita();
        }else{
            pulisci();
            cout<<"benvenuto in TO DO LIST"<<endl;
            cout<<"entrata nel programma..."<<endl;
            count();
        }

    while(scelta!=4){
        titolo();
        cout<<"                  1. lista dei to do"<<endl;//           menù principale
        cout<<"                  2. crea nuovo to do"<<endl;
        cout<<"                  3. spunta un to do come fatto"<<endl;
        cout<<"                  4. esci da to do list"<<endl;
        cout<<"========================================================================"<<endl;
    cin>>scelta;
    // consumiamo il newline lasciato da cin>> per permettere un uso corretto di getline()
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pulisci();
        switch(scelta){
            case 1:
                cout<<"=========================TO DO LIST====================================="<<endl;
                cout<<"                     lista dei to do:"<<endl;
                t=1;
                for(int i=0;i<todo.size();i++){
                    cout<<t<<". "<<todo[i]<<endl;
                    t++;
                }
                cout<<"inserisci qualsiasi valore per tornare al menu\' iniziale..."<<endl;
                cin>>q;
                pulisci();
                break;
            case 2:
                titolo();
                cout<<"inserisci nuovo to do: ";
                getline(cin, f);
                // se la stringa è vuota, chiediamo nuovamente (protezione minimale)
                if(f.empty()){
                    cout<<"input vuoto, nulla aggiunto. Premi invio per tornare al menu..."<<endl;
                    getline(cin, q);
                } else {
                    todo.push_back(f);
                    cout<<"aggiunto: "<<f<<endl;
                }
                pulisci();
                break;
            case 3:
                titolo();
                cout<<"lista dei to do:"<<endl;
                t=1;
                for(int i=0;i<todo.size();i++){
                    cout<<t<<". "<<todo[i]<<endl;
                    t++;
                }
                cout<<"========================================================================"<<endl;
                cout<<"        inserisci to do da spuntare come fatto: ";
                cin>>d;
                if(d >= 1 && d <= (int)todo.size()){
                    todo.erase(todo.begin() + d - 1);
                } else {
                    cout<<"indice non valido."<<endl;
                }
                cout<<endl;
                cout<<"azione completata con successo!"<<endl;
                dormi();
                cout<<"reindirizzamento al menu\' iniziale..."<<endl;
                this_thread::sleep_for(chrono::seconds(2));
                pulisci();
                break;
            case 4:
                uscita();
                break;
            default:
                cout<<"inserimento non valido"<<endl;
                uscita();
        }
    }
}