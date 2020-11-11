#include<iostream>
#include<vector>
using namespace std;

bool ePresente(int x, vector<int> & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
        {
            return true;
        }
    }

    return false;
}


bool eSullaDiagonale(int x, vector<int> & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
       if(sol.size()-i == abs(sol[i]-x))
            {
                return true;
            }
        
    }

    return false;
}


bool canAdd(int x, vector<int>  & sol)
{
    if(sol.empty())
    {
        return true;
    }

    if(!ePresente(x,sol) && !eSullaDiagonale(x,sol))
    {
        return true;
    }

    return false;

}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool isComplete(vector<int> & sol)
{
    if(sol.size()==4)
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
    int n=4;
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