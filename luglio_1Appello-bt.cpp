#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;


void add(int& x,vector<vector<string>>& S,vector<vector<string>>& sol)
{
    sol.push_back(S[x]);
}

bool canAdd(int& x,vector<vector<string>>& S,vector<vector<string>>& sol)
{
    if(sol.empty())
        return true;
    
    for(auto y : sol)
        if(y==S[x])
            return false;

    return true;
}

bool isComplete(vector<string>& U,vector<vector<string>>& S,vector<vector<string>>& sol,int& k)
{
    list<string> A;
    list<string> B;

    vector<string> str;

    for(int i=0;i<sol.size();i++)
    {
        for(int j=0;j<sol[i].size();j++)
            str.push_back(sol[i][j]);
    }



    for(auto x : U)
        A.push_back(x);

    for(auto x : str)
        B.push_back(x);

    A.sort();
    B.sort();

    return (A==B) && sol.size()<=k;
}

void remove(vector<vector<string>>& sol)
{
    sol.pop_back();
}   


bool bt(vector<string>& U,vector<vector<string>>& S,int& k,vector<vector<string>>& sol)
{
    int x = 0;

    while(x != S.size())
    {
        if(canAdd(x,S,sol))
        {
            add(x,S,sol);

            if(isComplete(U,S,sol,k)) return true;
            else if( bt(U,S,k,sol))   return true;

            remove(sol);
            x++;
        }
        else 
            x++;
    }

    return false;
}
int main()
{
    vector<string> U;
    vector<vector<string>> S;
    int k = 3;

    string a = "a";
    string b = "b";
    string c = "xq";
    string d = "e";
    string e = "f";

    U.push_back(a);
    U.push_back(b);
    U.push_back(c);
    U.push_back(d);
    U.push_back(e);

    vector<string> f; f.push_back("xq");    f.push_back("e");   f.push_back("f");
    vector<string> g; g.push_back("b");    g.push_back("e");   g.push_back("f");
    vector<string> h; h.push_back("a");    h.push_back("b");  
    vector<string> i; i.push_back("xq");    i.push_back("f");
    vector<string> l; l.push_back("a");    l.push_back("xq");   l.push_back("e");

    S.push_back(f);
    S.push_back(g);
    S.push_back(h);
    S.push_back(i);
    S.push_back(l);

    //cout<<"La size di U e': "<<U.size()<<endl;
    //cout<<"La size di S e': "<<S.size();

  
    vector<vector<string>> sol;

 
    if(bt(U,S,k,sol))
    {
        cout<<"SIUUUU"<<endl;
        cout<<"La dimensione di sol e': "<<sol.size()<<endl;
        for(int i=0;i<sol.size();i++)
        {
            for(int j=0;j<sol[i].size();j++)
                cout<<sol[i][j]<<" ";
            
            cout<<endl;
        }
    }
    else
    {
        cout<<"OH NO";
    }   


    // A SIMONE FUNZIONA TUTTO, IO HO DEI PROBLEMI SULLA STAMPA DEVO FARE PER BENE IL DEBUG */
    
    return 0;
}



    /* DEBUG INSERIMENTO OK 
    cout<<"STAMPA DI U "<<endl;
    for(auto x : U)
        cout<<x<<endl;

    cout<<"STAMPA DI S "<<endl;

    for(int i=0;i<S.size();i++)
    {
        for(int j=0;j<S[i].size();j++)
        {
            cout<<S[i][j]<<" ";
        }

        cout<<endl;
    }   */