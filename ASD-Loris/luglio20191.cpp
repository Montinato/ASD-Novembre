#include<iostream>
#include<utility>  
#include<vector>
#include "Grafo.hpp"
using namespace std;

    vector<pair<int,int>> conversazioni;
    
    vector<vector<int>> matrice ={  {1,2,3},
                                    {0,6},
                                    {4},
                                    {5,7}};

    int q=4;

bool noSingoli(int & x,vector<int> & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(conversazioni[sol[i]].first == conversazioni[x].first || 
            conversazioni[sol[i]].second == conversazioni[x].first || 
            conversazioni[sol[i]].second == conversazioni[x].second || 
            conversazioni[sol[i]].first == conversazioni[x].second)
            {
                return false;
            }
    }

    return true;
}

bool presente(int & x,vector<int> & sol)
{
    for(int i=0; i<sol.size(); i++)
    {
        if(sol[i]==x)
            return true;
    }

    return false;
}

bool perOgniInsiemeMassimoUno(int & x,vector<int> & sol)
{
    for(int i=0; i<matrice.size(); i++)
    {

        for(int j=0; j<matrice[i].size(); j++)
        {
                if(matrice[i][j]==x)
                    for(int w=0; w<sol.size(); w++)
                    {
                        for(int h=0; h<matrice[i].size(); h++)
                        {
                            if(matrice[i][h]==sol[w])
                            {
                                return false;
                            }
                        }
                    }
        }
    }

    return true;
}

bool canAdd(int & x,vector<int> & sol)
{
    if(noSingoli(x,sol) && !presente(x,sol) && perOgniInsiemeMassimoUno(x,sol))
    {
        return true;
    }

    return false;
}

bool isComplete(vector<int> & sol)
{
    if(sol.size()==q)
        return true;

    return false;
}

void add(int & x, vector<int> & sol)
{
    sol.push_back(x);
}

void remove(vector<int> & sol)
{
    sol.pop_back();
}

bool solve(vector<int> & sol)
{
    int x=0; 

    while(x<conversazioni.size())
    {
        if(canAdd(x,sol))
        {
            add(x,sol);

            if(isComplete(sol))
                return true;
            else if(solve(sol))
                return true;

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

    pair<int,int> aPair;
    
    aPair.first = 0;
    aPair.second = 1;
    conversazioni.push_back(aPair);

    aPair.first = 1;
    aPair.second = 3;
    conversazioni.push_back(aPair);

    aPair.first = 0;
    aPair.second = 3;
    conversazioni.push_back(aPair);

    aPair.first = 3;
    aPair.second = 2;
    conversazioni.push_back(aPair);

    aPair.first = 1;
    aPair.second = 2;
    conversazioni.push_back(aPair);

    aPair.first = 4;
    aPair.second = 5;
    conversazioni.push_back(aPair);

    aPair.first = 4;
    aPair.second = 3;
    conversazioni.push_back(aPair);

    aPair.first = 5;
    aPair.second = 3;
    conversazioni.push_back(aPair);


    vector<int> sol; // l'indice dell array che contiene le conversazioni

    if(solve(sol))
    {
        cout<<"OK"<<endl;

        for(int i=0; i<sol.size(); i++)
        {
            cout<<sol[i]+1<<endl;
        }

        for(int i=0; i<sol.size(); i++)
        {
            cout<<conversazioni[sol[i]].first+1<<" "<<conversazioni[sol[i]].second+1<<endl;
        }
    }

    return 0;
}