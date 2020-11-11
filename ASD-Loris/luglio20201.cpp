#include<iostream>
#include "Grafo.hpp"
using namespace std;


int somma(int i)
{
    int s=0;
    for(int j=0; j<g.n(); g++)
    {
        if(g(i,j)>0)
        {
            s+=g(i,j);
        }
    }

    return s;
}

bool verifica()
{
    for(int i=0; i<g.n(); i++)
    {
        for(int j=0; j<g.n(); j++)

            for(int k=0; k<g.n(); k++)

            if(!(somma(i)>g(j,k)) && g(i,j)>0 && g(j,k)>0 && i!=k)
            {
                return false;
            }
    }

    return true;
}