#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

void add(int& x,vector<pair<string,string>>& V,vector<pair<string,string>>& sol)
{
    sol.push_back(V[x]);
}

void remove(vector<pair<string,string>>& sol)  
{   
    sol.pop_back();
}

bool canAdd(int& x,vector<pair<string,string>>& V,vector<pair<string,string>>& sol)
{
    if(sol.empty())
        return true;

    for(auto elem : sol)
        if(V[x] == elem)
            return false;

    return true;
}

bool check(vector<pair<string,string>>& sol,vector<string>& porti)
{
    int collegamenti = 0;
    bool cond = false;

    for(int i=0;i<porti.size();i++)
    {
        for(int j=0;j<sol.size();j++)
        {
            for(int k=0;k!=sol.size() && k!=j;k++)
            {
                if((porti[i] == sol[j].first) || (porti[i] == sol[j].second) )
                {
                    if( (sol[k].first == porti[i] && sol[k].second != porti[i])  ||   (sol[k].second == porti[i] && sol[k].first != porti[i]) )  
                        collegamenti++;
                }
            }
        }

        if( (collegamenti == 0) || (collegamenti == 3) )
                cond = true;
        else
        {
            cond = false;
            return cond;
        }

        collegamenti = 0;
    }

    return true;
}

bool isComplete(vector<pair<string,string>>& V,vector<pair<string,string>>& sol,vector<string>& porti,int& h)
{
    return (check(sol,porti) && sol.size() == h);
}

bool bt(vector<pair<string,string>>& V,vector<string>& porti,vector<pair<string,string>>& sol,int& h)
{
    int x = 0;

    while( x != V.size())
    {
        if(canAdd(x,V,sol))
        {
            add(x,V,sol);

            if(isComplete(V,sol,porti,h))   return true;
            else if(bt(V,porti,sol,h))  return true;

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
    int n_rotte,n_porti,h;

    cin>>n_porti>>n_rotte>>h;

    string x,y;
    vector<pair<string,string>> V;

    for(int i=0;i<n_rotte;i++)
    {
        cin>>x>>y;

        pair<string,string> s;

        s.first = x;
        s.second = y;

        V.push_back(s);
    }

    list<string> list_porti;
    for(int i=0;i<V.size();i++)         // Inserisco tutti i porti presenti nelle rotte, poi li ordino e faccio unique
    {
        list_porti.push_back(V[i].first);
        list_porti.push_back(V[i].second);
    }

    list_porti.sort();
    list_porti.unique();

    vector<string> porti;
    for(auto it=list_porti.begin();it!=list_porti.end();it++)
        porti.push_back(*it);                     // Mi salvo tutti  i porti in un Vector


    vector<pair<string,string>> sol;


    if(bt(V,porti,sol,h))
    {
        for(int i=0;i<sol.size();i++)
        {
            cout<<sol[i].first<<" "<<sol[i].second<<endl;
        }

        cout<<"SIUUUUU"<<endl;
    }
    else
    {
        cout<<" OH NO "<<endl;
    }
    


        




    return 0;
}



    /*   
         6 8 6
         a b
         b e
         c b
         b d
         c d
         e d
         e c
         e f       */ 
         