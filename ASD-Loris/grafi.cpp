#include<iostream>
#include"Grafo.hpp"
using namespace std;


void scorriNodi(const Grafo &g)
{
    for(int i=0; i<g.n(); i++)
    {
        for(int j=0; j<g.n(); j++)
        {
            if(g(i,j))
            {
                cout<<"esiste nodo da : "<<i <<" a "<<j<<endl; 
            }
        }
    }
}

bool verifica(const Grafo & g)
{
    bool ok=false;
    cout<<g.n()<<endl;
    
    for(int i=0; i<g.n(); i++)
    {
        ok=false;
        for(int j=0, k=1; k<g.n(); j++, k++)
        {
            if(g(i,j) && g(i,k) && i!=j)
            {
                cout<<"esiste nodo da che rispetta la condizione : "<<i <<" a "<<j<<endl; 
                cout<<"esiste nodo da che rispetta la condizione : "<<i <<" a "<<k<<endl; 
                j++;
                k++;
                ok=true;
            }
        }
        if(!ok)
        {
            return false;
        }
    }
    return true;
}


bool ciclo(const Grafo & g)
{

    
    for(int i=0; i<g.n(); i++)
    {
        for(int j=0, k=1; k<g.n(); j++, k++)
        {
            if(g(i,j) && g(j,k) && g(k,i))
            {
                cout<<"ciclo su :"<<i+1<<j+1<<k+1<<endl;                
                return true;
            }
        }
    }
    return false;
}

void dfs(const Grafo& g, const int & nodoDiPartenza, vector<bool> & nodiRaggiunti )
{
    nodiRaggiunti[nodoDiPartenza]=true;

    for(int i=0; i<g.n();  i++)
    {
        if(i!=nodoDiPartenza && g(nodoDiPartenza,i) && nodiRaggiunti[i]==false)
        {
            dfs(g,i,nodiRaggiunti);//cambia i 
        }
    }
}

bool esisteCammino(const Grafo & g, int nodoDiPartenza)
{
    vector<bool> nodiRaggiunti(g.n(), false);

    dfs(g,nodoDiPartenza,nodiRaggiunti);
    for(int i=0; i<nodiRaggiunti.size(); i++)
    {
        if(nodiRaggiunti[i] && i!=nodoDiPartenza)
            cout<<"raggiunto il nodo"<<i<<endl;
    }
cout<<"/////////////////////////////////////"<<endl;

return true;
}

int main()
{
    Grafo g(5);

    g(0,1,true);
    g(0,2,true);
    g(1,2,true);
    g(1,3,true);
    g(2,0,true);
    g(2,1,true);
    g(3,0,true);
    g(3,1,true);
    g(3,2,true);
    g(4,0,true);
    g(4,1,true);

   // scorriNodi(g);

    //cout<<verifica(g);
    //cout<<ciclo(g);
    cout<<esisteCammino(g,0);


    return 0;
}