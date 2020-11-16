#include"Grafo.h"
#include"FunzioniGrafo.h"
#include<iostream>
#include<vector>
using namespace std;

bool isomorfi(Grafo& A,Grafo& B)
{
    FunzioniGrafo FG;
    vector<pair<int,int>> collA;
    vector<pair<int,int>> collB;
    pair<int,int> temp;

    for (int i = 1; i <= A.n(); i++)
    {
       for (int j = 1; j <= A.n() && j!=i; j++)
       {
           if(FG.esisteCammino(i,j,A))
           {
               temp.first = i;
               temp.second = j;
               collA.push_back(temp);
           }
       }
    }

    for (int i = 1; i <= B.n(); i++)
    {
       for (int j = 1; j <= B.n() && j!=i; j++)
       {
           if(FG.esisteCammino(i,j,B))
           {
               temp.first = i;
               temp.second = j;
               collB.push_back(temp);
           }
       }
    }

    /*  cout<<"Stampo i collegamenti di A: "<<endl;
    for(auto elemA : collA)
        cout<<elemA.first<<" "<<elemA.second<<endl;
    cout<<endl;  


    
     cout<<"Stampo i collegamenti di B: "<<endl;
    for(auto elemB : collB)
        cout<<elemB.first<<" "<<elemB.second<<endl;
    cout<<endl;     */

    if(collA.size() != collB.size())
        return false;

    bool ok = false;
    for(auto elemA : collA)
    {
        ok = false;
        
        for(auto elemB : collB)
        {
            if(elemA == elemB)
                ok = true;
        }
    }
    
    return ok && ( A.m()==B.m() );

}

int main()
{
    Grafo A(4);
    Grafo B(4);

    A(1,2,true);
    A(1,4,true);
    A(2,1,true);
    A(2,3,true);
    A(3,2,true);
    A(3,4,true);
    A(4,3,true);
    A(4,1,true);

    
    B(1,3,true);
    B(1,4,true);
    B(2,3,true);
    B(2,4,true);
    B(4,2,true);
    B(4,1,true);
    B(3,1,true);
    B(3,2,true);

    /*
    B(1,2,true);
    B(1,4,true);
    B(2,1,true);
    B(2,3,true);
    B(3,2,true);
    B(4,1,true);    */


    


    if(isomorfi(A,B))
        cout<<"SONO ISOMORFI"<<endl;
    else 
        cout<<"NON SONO ISOMORFI"<<endl;

}