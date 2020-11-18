#include"AlberoB.h"
#include"Grafo.h"
#include<string>
#include<list>
#include<iostream>
#include<queue>
using namespace std;

// Alberi 

int sommaNodi(AlberoB<int> A)
{
    if(A.nullo())
        return 0;

    return A.radice() + sommaNodi(A.figlio(SIN)) + sommaNodi(A.figlio(DES));
}

void visitaPrefissa(AlberoB<int> A,list<int>& L)     // passo sempre l'albero per copia
{
    if(!A.nullo())
    {
        visitaPrefissa(A.figlio(SIN),L);
        L.push_back(A.radice());
        visitaPrefissa(A.figlio(DES),L);
    }
}

int sommaNodiConLista(AlberoB<int> A)
{
    list<int> L;
    int somma = 0;

    visitaPrefissa(A,L);

    for(auto elem : L)
        somma += elem;

    return somma;
}

void visitaAnticipata(AlberoB<int> A)       // passo l'albero per copia
{
    if(!A.nullo())
    {
        cout<<A.radice();
        visitaAnticipata(A.figlio(SIN));
        visitaAnticipata(A.figlio(DES));
    }
}


int max(int x,int y) { return x>y; }

int profondita(AlberoB<int> A)      // profondita = max livello dei nodi dell'albero 
{
    if(A.nullo())
        return 0;

    int p1=0,p2=0;

    p1 = profondita(A.figlio(SIN));
    p2 = profondita(A.figlio(DES));

    return 1 + max(p1,p2);
}

// Grafo

bool esisteCammino(int i,int j,Grafo& G)        // OK FUNZIONA 
{
    queue<int> q;
    bool visitati[G.n()+1];

    for(int i=0;i<G.n()+1;i++)
        visitati[i] = false;

    q.push(i);
    visitati[i] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x==j)  return true;

        for(int k=1;k<=G.n() && k!=i;k++)
        {
            if(G(i,k) && !visitati[k])
            {
                q.push(k);
                visitati[k] = true;
            }
        }
    }
    return false;
}

bool cicloDaTre(Grafo& G)
{
    for(int i=1;i<=G.n();i++)
    {
        for(int j=1;j<=G.n();j++)
        {
            for(int k=1;k<=G.n();k++)
            {
                if( (i!=j)&&(j!=k)&& (i!=k) && G(i,j) && G(j,k) )
                    return true;
            }
        }
    }

    return false;
}

// Backtracking -> Bt 
bool backtracking()     // pseudocodice di prova 
{
    int x = 0;

    while( x <qualcosa.size())
    {
        if(canAdd(x,soluzione))     //Controllo se posso aggiungere
        {
            add(x,soluzione);       // Aggiungo

            if(isComplete(soluzione))   return true;        // Verifico che la soluzione sia completa
            else if(backtracking()) return true;            // Chiamata ricorsiva all'algoritmo di bt 

            x++;                                           // vado avanti e scorro
            remove(sol);                                // rimuovo
        }
        else
            x++;                                        // vado avanti e scorro
    }

    return false;
}

int main()
{


    return 0;
}