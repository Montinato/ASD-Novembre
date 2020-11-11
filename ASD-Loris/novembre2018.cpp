#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
                    //x   0       1       2       3       4       5
vector<string> parole={"malma","matma","magla","tagla","mamma","magma"};

bool eGiaPresenteLindice(vector<int>&sol, int x)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return true;
    }

    return false;
}

bool cambiandoUnaLettera(int k, int x)
{
    string p1=parole[k];//la parola da emulare
    string p2=parole[x];//la parola su cui cambiare una lettera


    for(int i=0; i<p1.length(); i++)
    {
        if(p1[i]!=p2[i])
        {
            p2[i]=p1[i];
            break;
        }
    }

    return p2==p1;
}

bool canAdd(int x, vector<int>  & sol)
{
    if(sol.empty())
    {
        return true;
    }

    for(int i=0; i<sol.size(); i++)
    {
        if(cambiandoUnaLettera(sol[i],x) && !eGiaPresenteLindice(sol, x) )
        {
           // cout<<"\n"<<parole[sol[i]]<<" - "<<parole[x];
            return true;
        }
    }

    return false;

}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool isComplete(vector<int> & sol)
{
    if(sol.size()==4)//n
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
    while (x < 6) //n
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
    int nParole=6;
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
    else
    {
        cout<<"NO";
    }
    

    return 0;
}