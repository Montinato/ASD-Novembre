#include<iostream>
#include<vector>
using namespace std;

    vector<int> numeri{12,5,8,14,3,8};

bool canAdd(int x, vector<int> & sol)
{
    for(int i=0; i<sol.size();i++)
    {
        if(sol[i]==x)
            return false;
    }

    return true;
}

bool add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool isComplete(vector<int> & sol)
{
    int s1=0;
    int s2=0;
    for(int i=0; i<sol.size(); i++)
    {
        s1+=numeri[sol[i]];
    }

    for(int i=0; i<numeri.size(); i++)
    {
        s2+=numeri[i];
    }

    if(s2-s1==s1)
        return true;

        return false;
}

void remove(int x, vector<int> & sol)
{
    sol.pop_back();
}


bool solve(vector<int> & sol)
{
    int x=0;

    while(x<numeri.size())
    {
        if(canAdd(x,sol))
        {
            add(x,sol);

            if(isComplete(sol))
                return true;
            
            else if(solve(sol))
                return true;

            remove(x,sol);
            x++;
        }
        else
            remove(x,sol);
            x++;
    }

    return false;
}

int main()
{


    vector<int> sol;

    if(solve(sol))
    {
        cout<<"Trovata una soluzione";
    }
    else
    {
        cout<<"No";
    }
    

    return 0;
}