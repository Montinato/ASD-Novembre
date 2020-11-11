#include<iostream>
#include "Grafo.hpp"
#include<vector>
#include<algorithm>
using namespace std;

vector<int>alunniV{42,8,5,9};

bool conosce(int k, int x, const Grafo & g)
{
    cout<<"3";
    if(k==0)
        return false;

    int y=0;

    for(int i=0; i<alunniV.size(); i++)
    {
        if(alunniV[i]==k)
            y=i;
    }

    if(g(y,x) || g(x,y))
    {
        return true;
    }
    return false;
}

bool controllaVicini(const int & x,int i, int j, int **sol,int c, int r,const Grafo & g)
{

cout<<"";
    if(conosce(sol[i][j+1],x,g) && j+1<c || conosce(sol[i][j-1],x,g) && j-1 >=0 || conosce(sol[i+1][j],x,g) && i+1<r || conosce(sol[i-1][j],x,g) && i-1>=0
    || conosce(sol[i-1][j+1],x,g) && i-1>=0 && j+1<c || conosce(sol[i+1][j-1],x,g) && i+1<r && j-1>=0 || conosce(sol[i+1][j+1],x,g) && i+1<r && j+1<c || conosce(sol[i-1][j-1],x,g) && i-1>=0 && j-1 >=0)
    {
        return false;
    }

    return true;

}


bool canAdd(const int &x, int **sol, int i, int j,const Grafo & g)
{

    int cont=0;

    for(int k=0; i<2; i++)
    {
        for(int y=0; j<3; j++)
        {
            if(sol[k][y]!=0)
            {
                cont++;
                cout<<"cont"<<cont;
            }
        }
    }

    if(cont==0)
    {
        return true;
    }

    if(sol[i][j]==0 && controllaVicini(x,i,j,sol,2,3,g))
    {
        return true;
    }

    return false;

}

void add(const int &x, int **sol,int i, int j)
{
    sol[i][j]=alunniV[x];
    cout<<"add" <<sol[i][j];
}

bool isComplete(int **sol)
{
    int cont=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(sol[i][j]!=0)
            {
                cont ++;
            }
        }
    }

    if(cont == 2)
    {
        cout<<"ok";
        return true;
    }

    return false;
}

void remove(const int & x,int ** sol)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(sol[i][j]==x)
            {
                sol[i][j]=0;
            }
        }
    }
    
}

int next(int x)
{
    x=x+1;
    return x;    
}

bool solve(int **sol,const Grafo & g)
{
    int x = 0;
    while (x < 4)//alunniV.size() 
    {
        for(int i=0; i<2;i++)
        {
            for(int j=0; j<3; j++)
            {

                if (canAdd(x,sol,i,j,g)) 
                {
                    cout<<"4"<<i<<j;
                    add(x,sol,i,j);

                    if (isComplete(sol))
                        return true;
                
                    else if (solve(sol,g))
                        return true;
                    
                    remove(x,sol);
                
                    x = next(x);
                } 
            else
                x = next(x);

            break;
            }
            break;
        }
    }
return false;
}

int main()
{
    int riga=2;
    int colonna=3;

    int alunni=4;
                    //  0 1 2 3


    Grafo g(4);
    g(0,2,true);
    g(2,0,true);
    g(1,2,true);
    g(2,1,true);
    g(1,3,true);
    g(3,1,true);
    g(3,0,true);
    g(0,3,true);

    int **sol;

    sol = new int *[riga];
    for(int i = 0; i < riga; i++) {
        sol[i] = new int [colonna];
    }
 
    for(int i = 0; i < riga; i++) {
        for(int j = 0; j < colonna; j++) {
            sol[i][j] = 0;
        }
    }

    if(solve(sol,g)) 
    {
        cout << "\nSI"<<endl;
        for(int i = 0; i < riga; i++) 
        {
            for(int j = 0; j < colonna; j++) 
            {
                if(sol[i][j] != 0) 
                {
                    cout << sol[i][j] << " = (" << i << "," << j <<")" << endl; 
                }
            }
        }
    }
    else 
    {
        cout << "NO";
    }

    for(int i=0; i<colonna; i++)
    {
        delete sol[i];
    }
    delete sol;

    return 0;
}