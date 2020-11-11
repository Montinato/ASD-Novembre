#include<vector>
#include<iostream>
using namespace std;

void add(int x,vector<vector<int>>& V,vector<vector<int>>& sol)
{
    sol.push_back(V[x]);
}

void remove(vector<vector<int>>& sol)   { sol.pop_back();   }

bool canAdd(int& x,vector<vector<int>>& V,int q,vector<vector<int>>& sol)
{
    if(sol.empty())
        return true;

    for(auto k : sol)
        if( k == V[x])
            return false;

    return true;
}

bool disgiunti(vector<vector<int>>& sol)
{
    vector<int> t1,t2;
    
    for(int i=0;i<sol.size();i++)
    {
        for(int j=0;j<sol.size() && j!=i;j++)
        {
            t1 = sol[i];
            t2 = sol[j];

            for(auto x : t1)
                for(auto y : t2)
                    if(x==y)
                        return false;

        }
    }

    return true;
}

bool isComplete(vector<vector<int>>& V,int& q,vector<vector<int>>& sol)
{
    return disgiunti(sol) && sol.size()>=q;
    
}

bool bt(vector<vector<int>>& V,int q,vector<vector<int>>& sol)
{
    int x = 0;

    while ( x != V.size())
    {
        if(canAdd(x,V,q,sol))
        {
            add(x,V,sol);

            if(isComplete(V,q,sol)) return true;
            else if(bt(V,q,sol))    return true;

            remove(sol);
            x++;
        }
        else
        {
            x++;
        }
    }

    return false;
}       

int main()
{
    vector<int> temp;
    vector<vector<int>> V;
    int q = 3;

    temp.push_back(4);  temp.push_back(-3); temp.push_back(2);
    V.push_back(temp);
    temp.clear();

    
    temp.push_back(11);  temp.push_back(42); temp.push_back(-3);
    V.push_back(temp);
    temp.clear();

    
    temp.push_back(-3);  temp.push_back(2); temp.push_back(11);
    V.push_back(temp);
    temp.clear();

    
    temp.push_back(8);  temp.push_back(11); temp.push_back(4);
    V.push_back(temp);
    temp.clear();

    
    temp.push_back(4);  temp.push_back(-3); temp.push_back(2); temp.push_back(11); temp.push_back(42);
    V.push_back(temp);
    temp.clear();

    
    temp.push_back(88);  temp.push_back(4); temp.push_back(8);
    V.push_back(temp);
    temp.clear();

    
    temp.push_back(2);  
    V.push_back(temp);
    temp.clear();


   /*   STAMPA DEL VECTOR<VECTOR> DI INSERIMENTO 
   for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }   */

    vector<vector<int>> sol;


    if(bt(V,q,sol))
    {
        cout<<"SIUUU"<<endl;

        for(int i=0;i<sol.size();i++)
        {
            for(int j=0;j<sol[i].size();j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"OH NO";
    }


    // OK FUNZIONA
    
    
    return 0;
}