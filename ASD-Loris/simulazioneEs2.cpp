#include<iostream>
#include<vector>
using namespace std;

int MIN_VAL=0;
int MAX_VAL=5;//n
    
    int m[5][5]={{0,1,1,0,0},
                {1,0,0,1,1},
                {1,0,0,1,0},
                {0,1,1,0,0},
                {0,1,0,0,0}};
int k=3;


bool presente(vector<int> & sol, int x)
{
    for(int i=0; i<sol.size();i++)
    {
        if(sol[i]==x)
            return true;
    }

    return false;
}

bool verifica(const int &x, vector<int> & sol)
{
    for(int s=0; s<sol.size(); s++)
    {
        int i=sol[s];

        if(m[i][x]==true)
            return false;
    }

    return true;
}

bool canAdd(const int &x, vector<int> & sol)
{
    if(sol.empty())
        return true;
    
    if(!presente(sol,x)  && verifica(x,sol))
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
    return sol.size()==k;
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

    int k=3;
    int n=5;
    vector<int> sol;

    if(solve(sol))
    {
        cout<<"Trovata una soluzione"<<endl;
    }
    else
    {
        cout<<"Nessuna sol trovata"<<endl;
    }

    for(int i=0; i<sol.size(); i++)
    {
        cout<<sol[i]<<" - ";
    }

}   