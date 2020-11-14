#include<iostream>
#include"GrafoPesato.hpp"
#include<vector>
using namespace std;

/*
    Scrivere una funzione chiamata esercizio1 che prenda in input il grafo e restituisca true se per ogni nodo u ∈ 𝑉, 
    la somma dei pesi degli archi uscenti da u è sempre maggiore dei singoli pesi di tutti gli archi uscenti dai nodi adiacenti di u; 
    altrimenti, restituisca false
*/

int sommaPesiArchiUscenti(int& nodo,GrafoPesato& Gp)
{
    int somma = 0;

    for(int i=0;i<Gp.n();i++)
    {
        if(Gp(nodo,i))
            somma += Gp.w(nodo,i);
    }

    return somma;
}

vector<int> pesiArchiUscenti(GrafoPesato& Gp,int& nodo)
{
    vector<int> V;

    for(int i=0;i<Gp.n();i++)
    {
        if(Gp(nodo,i))
            V.push_back(Gp.w(nodo,i));
    }

    return V;
}

vector<int> nodiAdiacenti(GrafoPesato& Gp,int& nodo)
{
    vector<int> V;

    for(int i=0;i<Gp.n();i++)
    {
        if(Gp(nodo,i))
            V.push_back(i);
    }

    return V;
}

bool esercizio1(GrafoPesato& Gp,int& nodo)
{
    int somma = sommaPesiArchiUscenti(nodo,Gp);
    vector<int> adiacenti = nodiAdiacenti(Gp,nodo);

    for(int i=0;i<adiacenti.size();i++)
    {
        vector<int> singoli = pesiArchiUscenti(Gp,adiacenti[i]);

        for(int j=0;j<singoli.size();j++)
        {
            if(somma < singoli[i])
                return false;
        }
    }

    return true;
}

int main()
{
    GrafoPesato Gp(5);
    int nodo = 0;
    bool ok = true;

    Gp(0,1,true,2);
    Gp(0,2,true,4);
    Gp(0,3,true,8);
    Gp(1,4,true,6);
    Gp(3,4,true,5);
    Gp(4,2,true,4);


    for(int i=0;i<Gp.n();i++)
    {
        nodo = i;
        if(!esercizio1(Gp,nodo))
            ok = false;
    }

    if(ok)
        cout<<"SIUUUU"<<endl;
    else
    {
        cout<<"OH NO"<<endl;
    }
    
    
    
    
    return 0;
}