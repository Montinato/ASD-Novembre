#include<iostream>
#include<vector>
#include"Grafo.hpp"
using namespace std;


                    //   0,  1,  2,  3,  4,  5
    vector<string> porti{"a","b","c","d","e","f"};
    
    int h=6;
    
    Grafo g(6);

struct Rotta
{
        int r1;
        int r2;
};
 
vector<Rotta> rotte;

bool presente(int x, vector<int>  & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return true;
    }

    return false;
}

bool canAdd(int x, vector<int>  & sol)
{
  /*  for(int j=0; j<sol.size(); j++)
        {
            cout<<rotte[sol[j]].r1<<" "<<rotte[sol[j]].r2<<endl;
        }
        cout<<"////////////////////////////"<<endl;
    */    
    if(sol.size()<h && !presente(x,sol))
        return true;

    return false;

}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool verifica(vector<int> & sol)
{
    for(int i=0; i<sol.size(); i++)
    {

        int cont=0;
        int cont2=0;

        for(int j=0; j<sol.size(); j++)
        {
            if((rotte[sol[i]].r1==rotte[sol[j]].r1 ) || (rotte[sol[i]].r1==rotte[sol[j]].r2 ))
            {
                cont++;
            }

            if((rotte[sol[i]].r2==rotte[sol[j]].r2 ) || (rotte[sol[i]].r2==rotte[sol[j]].r1))
            {
                cont2=3;
            }
        }

    if(cont==3 && cont2==3)
    {
        cout<<"*********"<<endl;
        cout<<"*********"<<endl;
        cout<<"*********"<<endl;
        cout<<"*********"<<endl;
    }

        if(cont!=3 || cont2!=3)
            return false;
    }

    return true;
}

bool isComplete(vector<int> & sol)
{
    if(sol.size()==h && verifica(sol))
        return true;
        
    return false;
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
    while (x < h ) 
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
    g(1,4,true);
    g(2,1,true);
    g(1,3,true);
    g(2,3,true);
    g(4,3,true);
    g(4,2,true);
    g(4,5,true);

    vector<int> sol; //l'indice della rotta che va bene


    for(int i = 0; i < g.n(); i++) 
     {    
        for(int j = 0; j < g.n(); j++) 
        {
            if(g(i,j)) 
            {
                Rotta r;
                r.r1 = i;
                r.r2 = j;
                rotte.push_back(r);
            }
               
        }
    }
 

 
    if(solve(sol)) 
    {
        cout << "SI" << endl;
        for(int i = 0; i < sol.size(); i++) 
        {
            cout << rotte[sol[i]].r1 << " " << rotte[sol[i]].r2 << endl;
        }
    }
    else 
    {
        cout << "NO";
    }


    return 0;
}