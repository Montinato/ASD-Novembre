#include<iostream>
#include"Grafo.hpp"
using namespace std;

int contaNodi(const Grafo & g, int i)
{
    int j=0;

    for(int k=0; k<g.n(); k++)
    {
        if(g(i,k))
        {
            j++;
        }
    }

    return j;

}

void verifica(const Grafo & g)
{
    
    for(int i=0; i<g.n(); i++)
    {
        int somma=contaNodi(g,i);
        for(int j=0; j<g.n(); j++)
        {
            if(g(i,j))
            {
                somma-=contaNodi(g,j);
            }
        }

        if(somma==0)
            cout<<"ok per : "<<i<<endl;
    }
}

int main()
{

    Grafo g(6);
    g(0,1,true);
    g(0,2,true);
    g(1,0,true);
    g(1,2,true);
    g(1,4,true);
    g(2,1,true);
    g(2,4,true);
    g(3,5,true);
    g(4,3,true);
    g(4,5,true);
    g(5,3,true);




    verifica(g);

    return 0;
}