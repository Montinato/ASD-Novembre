#include<iostream>
#include"Grafo.hpp"
using namespace std;


bool verifica(const Grafo & g)
{
    for(int i=0; i<g.n(); i++)
    {
        int cont=0;
        for(int j=0; j<g.n(); j++)
        {
            if(i!=j)
            for(int k=j+1; k<g.n(); k++)
            {
                if(g(i,j) && g(i,k) && k-j==1)
                {
                    //cout<<i<<j<<k;
                    cont++;
                    cout<<cont;
                }
            }
            if(cont<2)
            {
                return false;
            }
        }
    }
    return true;

}


void dfs(const Grafo & g, int a, vector<bool> &visitati)
{
	visitati[a]=true;

	for(int i=0; i<g.n(); i++)
	{
		if(g(a,i)&& a!=i && visitati[i]==false)
		{
			dfs(g,i,visitati);
		}
	}
}

bool esisteCammino(const Grafo & g, int a,int b)
{
	vector<bool>visitati(g.n(),false);

	dfs(g,a,visitati);

	return visitati[b];

}

bool verifica2(const Grafo & g)
{

	for(int i=0; i<g.n(); i++)
	{
		for(int j=0; j<g.n(); j++)
		{
			if(esisteCammino(g,i,j) && esisteCammino(g,j,i) && abs(j-i)>1)
            {
                cout<<"Esiste cammino da "<<i<<" a "<<j<<endl;
				//return true;
            }
		}
	}
	return false;
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


    //visita(g);

    if(verifica2(g))
        cout<<"OK";

    return 0;
}