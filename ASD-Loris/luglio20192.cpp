#include<iostream>
#include<vector>
using namespace std;

struct Indici
{
    int i1;//valore colonna
    int i2;
    int i3;
};
 
    int m[4][3]={{42,88,22},
                {7,8,1},
                {23,8,3},
                {23,888,4}};
 
    vector<Indici>incantesimi;
 
    int k=3;

bool verifica(const int & x, vector<int> & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return false;
    }

    return true;
}

bool canAdd(const int & x, vector<int> & sol)
{       
    if(sol.empty())
        return true;

    for(int i=0; i<sol.size(); i++)
    {
        if(!(incantesimi[sol[i]].i1!=incantesimi[x].i1 && 
        incantesimi[sol[i]].i2!=incantesimi[x].i2 && 
        incantesimi[sol[i]].i3!=incantesimi[x].i3) || !verifica(x,sol) )
        {
            return false;
        }
    }

    return true;

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

    vector<int>sol;
 
    for(int i=0;i<4;i++)
    {
        Indici ind;
        ind.i1=m[i][0];
        ind.i2=m[i][1];
        ind.i3=m[i][2];
        incantesimi.push_back(ind);//riempiamo di tuple incantesimi quindi t0=abc   t1=abc
    }


    
    if(solve(sol))
    {
        cout<<"OK\n"<<endl;

        for(int i=0; i<sol.size(); i++)
        {
            cout<<sol[i]<<endl;
        }
    }
    else
    {
        cout<<"NO";
    }
    

 
}

