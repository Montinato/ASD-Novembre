#include<iostream>
#include<vector>
using namespace std;


int MIN_VAL=0;
int MAX_VAL=5;//n
int n=5;
vector<int> dati ={4,12,3,88,192};
int w=207;

bool canAdd(const int &x, vector<int> & sol)
{
    
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return false;
    }

    int somma=0;
    for(int i=0; i<sol.size(); i++)
    {
        somma+=dati[sol[i]];
    }

    if(somma+dati[x]>w)
    {
        return false;
    }

    return true;

}

void add(const int &x, vector<int> & sol)
{
    sol.push_back(x);

}

bool isComplete(vector<int> &sol)
{
    int somma=0;
    for(int i=0; i<sol.size(); i++)
    {
        somma+=dati[sol[i]];
    }
   // cout<<somma;

    return somma==w;
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

bool solve(vector<int> &sol) 
{
    int x = MIN_VAL;
    while (x < MAX_VAL) 
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

    vector<int> sol;

    if(solve(sol))
    {
        cout<<"Trovata una soluzione"<<endl;;
    }
    else
    {
        cout<<"Nessuna sol trovata"<<endl;
    }
    
        for(int i=0; i<sol.size(); i++)
            cout<<sol[i];

}   