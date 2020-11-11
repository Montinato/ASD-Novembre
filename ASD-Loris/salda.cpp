#include<iostream>
#include "AlberoB.h"
#include<queue>

using namespace std;


bool verifica(const AlberoB<int> & a)
{

    if(!a.nullo())
    {

        queue<AlberoB<int>> coda;
        queue<int> livelli;

        coda.push(a);
        livelli.push(1);

        int livello_corrente=0;
        int livello_precedente=0;

        int somma=0;

        while (!coda.empty())
        {
            
            AlberoB<int> daValutare;
            daValutare=coda.front();
            coda.pop();

            livello_corrente=livelli.front();
            livelli.pop();

            if(livello_corrente==livello_precedente)
            {
                somma+=daValutare.radice();
            }
            else
            {
                if(somma>100)
                    return false;
                    
                somma=0;
                livello_precedente=livello_corrente;
            }
            

            if(!daValutare.figlio(SIN).nullo())
            {
                coda.push(daValutare.figlio(SIN));
                livelli.push(livello_corrente+1);
            }

            if(!daValutare.figlio(DES).nullo())
            {
                coda.push(daValutare.figlio(DES));
                livelli.push(livello_corrente+1);
            }

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


    if(verifica(a))
    {
        cout<<"OK";
    }

}