#include<iostream>
#include<vector>
#include"Grafo.hpp"
using namespace std;
                        //0     1     2      3     4
    vector<string>corsi={"ASD","PO","Fond","Arch","DS"};
    

    vector<pair<int,int>> possibili;//conterrà indice del corso e la fascia oraria(1-2-3)


bool controllaSeCe(const int &x, vector<int> & sol)
{
    int corso=possibili[x].first;

    for(int i=0; i<sol.size(); i++)
    {
        if(possibili[sol[i]].first==corso)
            return true;
    }

    return false;
}

bool ceUnoCheNonVoglioNellaStessaFascia(const int &x, vector<int> & sol,const Grafo & g)
{
    int fascia=possibili[x].second;
    int corso=possibili[x].first;
    
    for(int i=0; i<sol.size(); i++)
    {
       // cout<<"//////////////////////////////"<<endl;
       // cout<<"corso : "<<corso<<" "<<possibili[sol[i]].first<<endl;
      //  cout<<"//////////////////////////////"<<endl;

        if(possibili[sol[i]].second==fascia && ( g(corso,possibili[sol[i]].first) || g(possibili[sol[i]].first,corso) ))
        {
         //   cout<<"OK"<<endl;
            return true;
        }
    }

    return false;
}

bool canAdd(const int &x, vector<int> & sol,const Grafo & g)
{       
    if(!controllaSeCe(x,sol) && !ceUnoCheNonVoglioNellaStessaFascia(x,sol,g))
    {
        return true;
    }

    return false;
}

void add(const int &x, vector<int> & sol)
{
    sol.push_back(x);
}


bool isComplete(vector<int> &sol)
{
    if(sol.size()==corsi.size())
    {
        return true;
    }

    return false;
}

void remove(const int & x,vector<int> & sol)
{
    sol.pop_back();
}

int next(int x)
{
    x=x+1;
    return x;    
}



bool solve(vector<int> &sol, const Grafo& g) 
{
    int x = 0;
    while (x < 15) //possibili.size()
    {
        if (canAdd(x,sol,g)) 
        {
            add(x,sol);
            if (isComplete(sol))
                return true;
        
            else if (solve(sol,g))
                return true;
            
            remove(x,sol);
        
            x = next(x);
        } 
    else
        x = next(x);
    }

return false;
}

int main()
{
    int c=5;
    int collegamenti=5;


    Grafo g(5);
    g(0,4,true);
    g(0,1,true);
    g(0,2,true);
    g(1,2,true);
    g(2,3,true);

    for(int i=0; i<corsi.size(); i++)//mi scorro i corsi indici
    {
        for(int j=1; j<=3; j++)//mi scorro le fasce  orarie (3)
        {
            possibili.push_back(make_pair(i,j));//creo quindi 0,1-0,2-0,3 ecc..
        }
    }

    vector<int> sol; // è l'indice della combinazione che mi va bene in possibili

    if(solve(sol,g))
    {
        cout<<"OK\n";
        for(int i=0; i<sol.size(); i++)
        {
            cout<<corsi[possibili[sol[i]].first]<<" , "<<possibili[sol[i]].second<<endl;
        }
    }

    return 0;
}