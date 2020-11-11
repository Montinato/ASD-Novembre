#include<iostream>
#include<vector>
#include "Grafo.hpp"
using namespace std;


    int n=4;
    int k=3;
                        // 0            1       2       3
    vector<string> citta={"Xinghua", "Modiin", "Apaas","Ukiah"};
    Grafo g(4);


bool presente (int x, vector<int>  & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(x==sol[i])
            return true;
    }

    return false;
}


bool canAdd(int x, vector<int>  & sol)
{

    for(int i=0; i<sol.size(); i++)
    {
        if(g(x,sol[i]) || presente(x,sol) )
            return false;
    }

    return true;
}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool isComplete(vector<int> & sol)
{
    int cont=sol.size();

    for(int i=0; i<sol.size(); i++)
    {
        for(int j=0; j<4; j++)
        {
            if(g(sol[i],j))
            {
                cont++;
            }
        }
    }

    return cont==4 && sol.size()<=3;
}

void remove(int x, vector<int> & sol)
{
    sol.pop_back();
}

int next(int x)
{

    return x+1;

}

bool solve(vector<int>  & sol) 
{
   int x = 0;
    while (x < 4) 
    {
        if (canAdd(x,sol)) 
        {
            add(x,sol);
            if (isComplete(sol))
                return true;
            else if (solve(sol))
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

    
    g(0,1,true);
    g(1,0,true);
    g(1,2,true);
    g(2,1,true);

    vector<int> sol;

    if(solve(sol))
    {
        cout<<"Ho trovato una soluzione\n";

        for(int i =0; i<sol.size(); i++)
        {
            cout<<sol[i]<<endl;
        }
    }

    return 0;
}