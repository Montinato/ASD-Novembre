#include"Grafo.h"
#include<iostream>
#include<queue>
using namespace std;

bool esisteCammino(int i,int j,Grafo& G)
{
    queue<int> q;                   // Lista in cui mi conservo i nodi da visitare
    bool visitati[G.n() + 1];       // Array che tiene conto di ciò che ho visitato 

    for(int i=0;i<G.n()+1;i++)
        visitati[i] = false;                // Setto tutto l'array a false 

    q.push(i);                      // Inserisco all'interno della lista l'elemento i che passo all funzione 
    visitati[i] = true;             // Di conseguenza faccio visitati[i] = true

    while(!q.empty())
    {
        int x = q.front();          // Assegno ad una variabile l'elemento che ho inserito nella lista 
        q.pop();                    // E lo rimuovo dalla lista stessa 

        if(x == j) 
            return true;            // Ovviamente se la x coincide con j return true

        for(int k=1;k<=G.n();k++)               // Scorro i nodi del grafo
        {
            if(G(x,k) && k!=x && !visitati[k])      
            {
                // Se esiste un arco tra x e k e non ho ancora visitato k, aggiungo k a q e visitati[k] = true
                q.push(k);
                visitati[k] = true;
            }
        }
    }
    return false;
}


int main()
{
    Grafo G(5);
    // FunzioniGrafo fg;

    // Prendo da esempio il grafo del primo appello di Luglio 2020
    G(1,2,true);
    G(1,3,true);
    G(1,4,true);
    G(2,5,true);
    G(5,3,true);
    G(4,5,true);

    if(esisteCammino(1,5,G))
        cout<<"SIUUUUU";
    else 
        cout<<"OH NO";


    return 0;
}



    /*  STAMPA DEL GRAFO 
    for(int i=1;i<=G.n();i++)
    {
        for(int j=1;j<=G.n();j++)
        {
            if(G(i,j))
                cout<<"Esiste l'arco "<<i-1<<" "<<j-1<<endl;
        }
    }       OK L'INSERIMENTO E' GIUSTO */