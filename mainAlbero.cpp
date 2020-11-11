#include"AlberoB.h"
#include<list>
#include<queue>
#include<iostream>
#include<string>
using namespace std;

// VISITA ANTICIPATA/PREFISSA/PREORDINA
void prefix(const AlberoB<bool>& A)
{
    if(!A.nullo())
    {
        //Stampo il nodo radice
        cout<<"Sono sul nodo : "<<A.radice()<<endl;
        //Stampo il figlio sinistro
        prefix(A.figlio(SIN));
        //Stampo il figlio destro
        prefix(A.figlio(DES));
    }
}

AlberoB<int> ricercaPerLivelli(const AlberoB<int>& A, int x)
{
    if(!A.nullo())
    {
        queue<AlberoB<int>> coda;

        coda.push(A);

        while(!coda.empty())
        {
            AlberoB<int> daValutare = coda.front();     // elemento in testa
            coda.pop();

            // Se ho trovato l'albero che mi interessa lo restituisco
            if(x == daValutare.radice())
                return daValutare;


            // Inserisco i figli nella coda se esistono
            if(!daValutare.figlio(SIN).nullo())
                coda.push(daValutare.figlio(SIN));
            if(!daValutare.figlio(DES).nullo())
                coda.push(daValutare.figlio(DES));
        }
    }

    return AlberoB<int>();      // Restituisco un AlberoB vuoto
}

 
//int main()
//{

   
  /*              Voglio rappresentare: 
                        42
                12             2
                    8


        Quando scrivo: AlberoB<int> A(42) significa che il contenuto informativo di A è 42
                       Per comporre l'albero rappresentato su dovrò quindi creare diversi 
                       "AlberoB" con il contenuto informativo che mi interessa. Ad esempio:

                       Voglio inserire 12 e 2 che sono rispettivamente figlio Sx e figlio Dx,
                       creerò 2 alberi nuovi con contenuto informativo 12 e 2. AlberoB<int> B(12);  AlberoB<int> C(2);
                       E così via....
    */ 

    /* INSERIMENTO PREFIX E RICERCA PER LIVELLI
    AlberoB<int> A(42);
    AlberoB<int> B(12);     // Figlio sinistro albero A
    AlberoB<int> C(2);     // Figlio destro albero A
    AlberoB<int> D(8);      // Figlio destro albero B


    A.insFiglio(SIN,B);         // Per assegnare i figlio passò la direzione e l'AlberoB ( che contiene il contenuto informativo 12)
    A.insFiglio(DES,C);
    B.insFiglio(DES,D);


    prefix(A);  


    string temp = "";
    AlberoB<int> A(-1);        // radice di tutto l'albero che andrò a leggere

    // Prima Iterazione
    getline(cin,temp);              // leggo e metto tutto dentro temp
    int valRadice = std::stoi(temp);       // stoi converte la stringa in intero
    A.modRadice(valRadice);             // modifico la radice

    while(getline(cin,temp))
    {
        // Ultima Riga ( l'input finisce con "-1")
        if(temp == "-1")
            break;


        // Tutte le altre righe del tipo :      x:y dir
        int direzione = -1;

        // Se l'ultima lettera e' S direzione = SIN , altrimenti direzione = DES
        if(temp[temp.size()-1] == 's')
            direzione = SIN;
        else
            direzione = DES;

        // stringa.find('x') -> Restituisce l'indice del carattere x dentro la stringa
        int indiceDuePunti = temp.find(':');            //2
        int indiceSpazio = temp.find(' ');              //5

        
        // .substr(x,y), x = indice da cui partire, y = lunghezza della sottostringa
        string sottostringaSinistra = temp.substr(0,indiceDuePunti);        // 15
        string sottostringaDestra= temp.substr(indiceDuePunti+1,indiceSpazio - indiceDuePunti); //  10

        int valoreDaInserire = std::stoi(sottostringaSinistra);
        int padre = std::stoi(sottostringaDestra);

        // Devo cercare padre dentro A e poi inserire valoreDaInserire in padre con quella direzione
        AlberoB<int> alberoTrovato = ricercaPerLivelli(A,padre); 
        if(alberoTrovato.nullo())
        {
            cout<<"Non trovato"<<endl;
            return 0;
        }
        

        AlberoB<int> alberoDaInserire(valoreDaInserire);
        alberoTrovato.insFiglio((Direzione) direzione,alberoDaInserire);
    }


    prefix(A);



    return 0;
}

*/