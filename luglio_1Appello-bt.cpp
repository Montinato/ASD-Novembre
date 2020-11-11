#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void remove(vector<vector<string>>& sol)    
{ 
    //cout<<"Metodo Remove "; 
    sol.pop_back(); 
}     // OK

void add(int x,vector<vector<string>>& sol,vector<vector<string>>& S)       // OK
{
    //cout<<"Metodo add, Ho aggiunto alla soluzione l'array di stringhe in posizione: "<<x<<endl;
    sol.push_back(S[x]);
}

bool canAdd(int x,vector<vector<string>>& sol,vector<vector<string>>& S,int k)  // OK
{

    //cout<<"Metodo canAdd, se non supero k posso aggiungere"<<endl; 

    if(sol.empty())
        return true;

    for(int i=0;i<sol.size();i++)
    {
        if(sol[i] == S[i])
            return false;
    }

    return sol.size() + 1 <= k;
}

bool isComplete(vector<vector<string>>& sol,vector<string>& U,int k)    // OK
{
   // cout<<"Metodo isComplete "<<endl;

    if(sol.empty())
        return false;
    else
    {
        vector<string> temp_sol;        // inserisco in un vector temporaneo tutte le stringhe di sol
        vector<string> temp_U ;        // inserisco un un vector temporaneo le stringhe di U

        for(int i=0;i<U.size();i++)
            temp_U.push_back(U[i]);

        for(int i=0;i<sol.size();i++)
        {
        // cout<<"ENTRO QUA"<<endl;
            for(int j=0;j<sol[i].size();j++)
            {
                //cout<<"INSERISCO IN TEMP_SOL"<<endl;
                temp_sol.push_back(sol[i][j]);
            }
        }

        sort(temp_U.begin(),temp_U.end());
        sort(temp_sol.begin(),temp_sol.end());

        for(int i=0;i<temp_U.size();i++)
            if(temp_U[i] != temp_sol[i])
                return false;
    }
            
    return  true;
}

bool bt(vector<string>& U, vector<vector<string>>& S,int k,vector<vector<string>>& sol)
{
    int x = 0;

   // cout<<" bt while "<<endl;
    while( x <= S.size())
    {
      //  cout<<" bt canAdd "<<endl;
        if(canAdd(x,sol,S,k))
        {
           // cout<<" bt add "<<endl;
            add(x,sol,S);

           // cout<<" bt isComplete "<<endl;
            if(isComplete(sol,U,k)) return true;
           // cout<<" bt richiamo bt "<<endl;
             if(bt(U,S,k,sol))  return true;

           // cout<<" bt remove "<<endl;
            remove(sol);
            //cout<<" bt x++ "<<endl;
            x++;
        }
        else
        {
           // cout<<" bt else x++ "<<endl;
            x++;
        }
        
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

   // sol.push_back(f);
   //  sol.push_back(h);
   

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


    // A SIMONE FUNZIONA TUTTO, IO HO DEI PROBLEMI SULLA STAMPA DEVO FARE PER BENE IL DEBUG

    
    
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