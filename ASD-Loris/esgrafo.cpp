#include<iostream>
#include<vector>
#include<queue>
#include"Grafo.hpp"
using namespace std;


void bfs(const Grafo & g, int x, vector<bool> & visitati)
{

    queue<int> q;
    q.push(x);
    
    visitati[x]=true;

    while (!q.empty())
    {
        int daValutare=q.front();
        q.pop();
        cout<<daValutare<<endl;


        for(int i=0; i<g.n(); i++)
        {
            if(daValutare!=i && g(daValutare,i) && visitati[i]==false)
            {
                q.push(i);
                visitati[i]=true;
            }
        }
    }
}

void dfs ( const Grafo & g, int x, vector<bool> & visitati)
{
    visitati[x]=true;

    for(int i=0; i<g.n(); i++)
    {
        if(x!=i && g(x,i) && !visitati[i])
            dfs(g,i,visitati);
    }
}


int main()
{
    Grafo g(5);

    /*g(0,1,true);
    g(0,2,true);
    g(1,2,true);
    g(1,3,true);
    g(2,0,true);
    g(2,1,true);
    g(3,0,true);
    g(3,1,true);
    g(3,2,true);
    g(4,0,true);
    g(4,1,true);*/

    g(0,1,true);
    g(0,3,true);
    g(1,2,true);
    g(2,3,true);
    g(3,4,true);



    vector<bool> visitati (g.n(), false);

    //dfs(g,4,visitati);
    bfs(g,0,visitati);
    
    cout<<"///////////////////////\n";
    
    for(int i=0; i<visitati.size(); i++)
    {
        if(visitati[i])
        cout<<i<<endl;
    }


    return 0;
}