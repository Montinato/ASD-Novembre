#include<iostream>
#include"AlberoB.h"
#include<queue>
using namespace std;

void visitaPerLivelli(const AlberoB<int> & a)
{

    queue<AlberoB<int>> coda;
    coda.push(a);

    while(!coda.empty())
    {
        AlberoB<int> daValutare= coda.front();
        coda.pop();

        cout<<daValutare.radice()<<" ";

        if(!daValutare.figlio(SIN).nullo())
        {
            coda.push(daValutare.figlio(SIN));
        }
        
        if(!daValutare.figlio(DES).nullo())
        {
            coda.push(daValutare.figlio(DES));
        }

    }
}


int main()
{
    AlberoB<int> a(12);
    AlberoB<int> b(4);
    AlberoB<int> c(2);
    AlberoB<int> d(200);
    a.insFiglio(SIN,b);
    a.insFiglio(DES,c);
    c.insFiglio(DES,d);

    visitaPerLivelli(a);
    
    return 0;
}