#include"Grafo.h"
#include"FunzioniGrafo.h"
#include<iostream>
using namespace std;


int f(Grafo& G,int nodo)
{
    int nodiNonRaggiungono = 0;
    FunzioniGrafo F;


    for(int j=1;j<=G.n();j++)
    {
        if(( !F.esisteCammino(j,nodo,G))  )
        {
            nodiNonRaggiungono++;
        }
    }

    return nodiNonRaggiungono;
}


int main()
{
    Grafo G(5);
    FunzioniGrafo F;
    int nodo = 0,cont = 0;

    G(1,2,true);
    G(1,5,true);
    G(2,5,true);
    G(4,2,true);
    G(3,4,true);

    int max = -100;
    int temp = 0;

    for(int i=1;i<=G.n();i++)
    {
        temp = f(G,i);
        
        if(temp > max)
        {
            max = temp;
            nodo = i;
        }
        //cout<<"N: "<<i-1<<" non lo raggiungono : "<<temp<<" nodi"<<endl;
    }

    cout<<"Nodo : "<<nodo-1<<" valore: "<<max<<endl;
        

}