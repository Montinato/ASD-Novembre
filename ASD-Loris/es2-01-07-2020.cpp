#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> S={{"xq","e","f"},{"b","e","f"},{"a","b"},{"xq","f"},{"a","xq","e"}};
vector<string> U={"a","b","xq","e","f"};

int z=3;

bool verifica(int x, vector<int>  & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
        return false;
    }

    return true;
}

bool canAdd(int x, vector<int>  & sol)
{
    int cont =0;

    for(int i=0; i<S[x].size(); i++)
    {   
        for(int j=0; j<U.size(); j++)
        {
            if(S[x][i]==U[j])
                cont++;
        }
    }

    if(cont==S[x].size() && verifica(x,sol))
        return true;

        return false;

}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool verificaFine(vector<int> & sol)
{
    int cont=0;

    for(int i=0; i<sol.size(); i++)
    {
        for(int j=0; j<S[sol[i]].size(); j++)
        {
            for(int k=0; k<U.size(); k++)
            if(S[sol[i]][j]==U[k])
                cont++;
        }
    }

    if(cont==U.size())
    return true;

    return false;
}

bool isComplete(vector<int> & sol)
{
    if(sol.size()==z && verificaFine(sol))
    {
        return true;
    }

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
    while (x < S.size()) 
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

        for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<endl;
    }
    else
    {
        cout<<"NO";
    }
    

    return 0;
}