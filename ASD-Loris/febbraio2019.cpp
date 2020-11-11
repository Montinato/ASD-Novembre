#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string p="hope";
string parolaDaEmulare="role";
int nParole=7;

                    //x   0       1     2    3       4       5      6
vector<string> parole={"peta","atpe","hope","sole","rope","role","sope"};

bool eGiaPresenteLindice(vector<int>&sol, int x)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return true;
    }

    return false;
}

int cambioValido(int x, vector<int> &sol)
{
    string p1="";

    if(sol.empty())
    {
        p1=p;
    }
    else
    {
        p1=parole[sol[sol.size()-1]];//ultima parola su cui siamo rimasti 
    }
    
    string p2=parolaDaEmulare;

    string cambio="";

    for(int i=0; i<p1.length(); i++)
    {
        if(p1[i]!=p2[i])
        {
            p1[i]=p2[i];
            cambio=p1;
            break;
        }
    }


    if(parole[x]==cambio)
        return true;


    return false;

}

bool canAdd(int x, vector<int>  & sol)
{
    
    if(cambioValido(x,sol))
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
    if(parole[sol[sol.size()-1]]==parolaDaEmulare)
    return true;

    return false;
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
    while (x < nParole) //nParole
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
            cout<<parole[sol[i]]<<endl;
        }
    }
    else
    {
        cout<<"NO";
    }
    

    return 0;
}