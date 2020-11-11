#include<iostream>
#include"AlberoB.h"
#include<queue>
#include<string>
using namespace std;


void determinaProprieta(const AlberoB<int> & a)
{
    if(!a.nullo())
    {
        queue<AlberoB<int>> coda;
        queue<int> livelli;

        coda.push(a);
        livelli.push(1);
        int livelloCorrente=0,
            livelloPrecedente=1;
        
        int somma=0;


        while (!coda.empty())
        {

            AlberoB<int> daValutare;
            daValutare=coda.front();
            coda.pop();

            livelloCorrente=livelli.front();
            livelli.pop();

            if(livelloCorrente==livelloPrecedente)
            {
                somma+=daValutare.radice();
            }
            else
            {
                if(somma>100)
                    cout<<"S : "<<somma<<" L : "<<livelloCorrente<<endl;
                somma=0;
                somma+=daValutare.radice();
                livelloPrecedente=livelloCorrente;
            }
            //cout<<"S : "<<somma<<" L : "<<livelloCorrente<<endl;

            if(!daValutare.figlio(SIN).nullo())
            {
                coda.push(daValutare.figlio(SIN));
                livelli.push(livelloCorrente+1);
            }
                
            if(!daValutare.figlio(DES).nullo())
            {
                coda.push(daValutare.figlio(DES));
                livelli.push(livelloCorrente+1);
            }
            
         if(somma>100)
                    cout<<"S : "<<somma<<" L : "<<livelloCorrente<<endl;
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

    determinaProprieta(a);
    
    return 0;
}