#include<iostream>
#include<vector>
using namespace std;

    int riga=2;
    int colonna=3;

    int alunni=4;
                        //0, 1, 2,3
    vector<int> studenti ={42,8,5,9};

    int m[riga][colonna];


    Grafo g(4);

bool canAdd(const int &x, vector<pair<int,int>>& sol)
{       

}

void add(const int &x, vector<pair<int,int>>& sol)
{
    
    sol.push_back(x);
}


bool isComplete(vector<pair<int,int>>& sol)
{
    return sol.size()==studenti.size();
}

void remove(const int & x,vector<pair<int,int>>& sol)
{
    int studente=studenti[x];

    for(int i=0; i<riga; i++)
    {
        for(int j=0; j<colonna; j++)
        {
            if(m[i][j]==studente)
            {
                m[i][j]=0;
            }
        }
    }

    sol.pop_back();
}

int next(int &x)
{
    x=x+1;
    return x;    
}


bool solve(vector<pair<int,int>> &sol) 
{
    int x = 0;
    while (x < studenti.size())
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

    g(0,1,true);
    g(1,0,true);
    g(1,2,true);
    g(2,1,true);
    g(1,3,true);
    g(3,1,true);
    g(2,0,true);
    g(0,2,true);
    g(3,0,true);
    g(0,3,true);

   
    vector<pair<int,int>> sol;//le coordinate degli studenti con pos uguale a vector studenti

    if(solve(sol))
    {
        cout<<"OK"<<endl;
        for(int j=0; j<dim; j++)
        {
            cout<<sol[j].first<<" , "<<sol[j].second<<endl;
        }
    } 

    
    return 0;
}