#include<iostream>
#include<vector>
using namespace std;

int MIN_VAL=0;
int MAX_VAL=4;//n


bool controllaColonna(int x, vector<int>& sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return true;
    }

return false;        
}



bool controllaDiagonale(int x, vector<int>& sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(abs(sol[i]-x) == sol.size()-i)
            return true;
    }

return false;        
}

bool canAdd(const int &x, vector<int> & sol)
{

    if(sol.empty())
        return true;


        if(controllaColonna(x,sol) || controllaDiagonale(x,sol))//sulla stessa colonna o sulla stessa diagonale
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
    return sol.size()==4;
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

    int n=4;
    vector<int> sol;

    if(solve(sol))
    {
        cout<<"Trovata una soluzione"<<endl;
    }
    else
    {
        cout<<"Nessuna sol trovata";
    }
    

for(int i=0; i<sol.size(); i++)
{
    cout<<sol[i]<<" - ";
}

}   