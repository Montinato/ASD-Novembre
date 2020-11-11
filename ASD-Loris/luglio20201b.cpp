#include<iostream>
#include<vector>
using namespace std;


    vector<string> U= {"a","b","xq","e","f"};
    int k=3;
    vector<vector<string>> S = {{"xq", "e", "f"},
                                {"b", "e", "f"},
                                {"a", "b"},
                                {"xq", "f"},
                                {"a","xq","e"}};




bool canAdd(int x, vector<int>  & sol)
{
    int cont=0;

    for(int i=0; i<S[x].size(); i++)
    {
        for(int j=0; j<U.size(); j++)
        {
            if(S[x][i]==U[j])
            {
                cont++;
            }   
        } 
    }

    return cont==S[x].size()  && sol.size()+1<=k;
}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}


bool isComplete(vector<int> & sol)
{
    int cont=0;

    for(int i=0; i<sol.size(); i++)
    {
        for(int j=0; j<S[sol[i]].size(); j++)
        {
            for(int k=0; k<U.size(); k++)
            {
                if(S[sol[i]][j]==U[k])
                {
                    cont++;
                }
            }
        }
    }

    return cont==U.size();

}

void remove(int x, vector<int> & sol)
{
    sol.pop_back();
}

int next(int x)
{
    int j=x+1;
    return j;

}

bool solve(vector<int>  & sol) 
{
   int x = 0;
    while (x <5) 
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
        cout<<"Ho trovato una soluzione\n";

        for(int i =0; i<sol.size(); i++)
        {
            cout<<sol[i]<<endl;
        }
    }
    else
    {
        cout<<"NO";
    }


    return 0;
}