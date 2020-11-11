#include<iostream>
#include<vector>
using namespace std;

    
    vector<int> numeri={4,12,3,88,192};
    int w=207;

bool presente(int x, vector<int>  & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return true;
    }

    return false;
}

bool vaBene(int x, vector<int>  & sol)
{
    int somma=0;
    for(int i=0; i<sol.size(); i++)
    {
        somma+=numeri[sol[i]];
    }

    if(somma+numeri[x]<=w)
    {
        return true;
    }

    return false;

}

bool canAdd(int x, vector<int>  & sol)
{
    if(sol.empty() && numeri[x]<=w)
    return true;

    if(!presente(x,sol) && vaBene(x,sol))
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
    int somma=0;

    for(int i=0; i<sol.size(); i++)
    {
        somma+=numeri[sol[i]];
    }
    return somma==w;
}

void remove(int x, vector<int> & sol)
{
    sol.pop_back();
}


bool solve(vector<int> &sol) 
{
    int x = 0;
    while (x < 5) 
    {
        if (canAdd(x,sol)) 
        {
            add(x,sol);
            if (isComplete(sol))
                return true;
        
            else if (solve(sol))
                return true;
            
            remove(x,sol);
        
            x ++;
        } 
    else
        x ++;
    }

return false;
}


int main()
{

    vector<int> sol;


    if(solve(sol))
    {
        cout<<"Ho trovato una soluzione\n";

        for(int i =0; i<sol.size(); i++)
        {
            cout<<numeri[sol[i]]<<endl;
        }
    }
    else
    {
        cout<<"NO";
    
        
    for(int i=0; i<sol.size(); i++)
    {
        cout<<numeri[sol[i]]<<endl;
    }
    cout<<"///////////////////"<<endl;

    }
    

    return 0;
}