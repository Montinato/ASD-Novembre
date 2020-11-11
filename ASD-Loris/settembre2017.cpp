#include<iostream>
#include"AlberoB.h"
using namespace std;

bool radiceTrue(const AlberoB<bool> & uno)
{
    return uno.radice();
}

bool foglieTrue(const AlberoB<bool> & uno)
{

    if(uno.foglia() && uno.radice()!=true)
        return false;
    
    bool r=true;
    bool l=true;

    if(!uno.figlio(SIN).nullo())
        l=foglieTrue(uno.figlio(SIN));
        
    if(!uno.figlio(DES).nullo())
        r=foglieTrue(uno.figlio(DES));

    return r && l;

}

bool entrambiFigliTrue(const AlberoB<bool> & uno)
{
    if(!uno.figlio(SIN).nullo() && !uno.figlio(DES).nullo())
    
    if(uno.figlio(SIN).radice() == true && uno.figlio(DES).radice() == true)
    {
        return true;
    }

    return false;
    
}

bool l=true;
bool r= true;

bool verificaFigliTrue(const AlberoB<bool> & uno)
{


    if (uno.radice()==false && !entrambiFigliTrue(uno))
    {
        return false;
    }
    else
    {

        if(!uno.figlio(SIN).nullo())
            l=verificaFigliTrue(uno.figlio(SIN));

        if(!uno.figlio(DES).nullo())
            r=verificaFigliTrue(uno.figlio(DES));
    }

    return l && r;
    
}


int countTrue(const AlberoB<bool>& albero)
{
    int iter = 1;

    /*
        Per ogni nodo, tutti i cammini da quel nodo alle rispettive foglie contengono lo stesso numero di
        nodi con attributo True
    */
    
    int b1, b2;

    if(!albero.figlio(SIN).nullo())
        b1 = countTrue(albero.figlio(SIN));
    else
        b1 = 0;

    cout<<"Stampo b1: "<<b1<<endl;
    cout<<"Iterazione: "<<iter<<endl;
    

    if(!albero.figlio(DES).nullo())
        b2 = countTrue(albero.figlio(DES));
    else
        b2 = 0;

    cout<<"Stampo b2: "<<b2<<endl;
    cout<<"Iterazione: "<<iter<<endl;
    iter++;
    
    if(b1 != b2)
    {
        cout<<"b1: "<<b1<<"b2: "<<b2<<endl;
        return -1;
    }
    
    if(b1 == -1 || b2 == -1)
    {
        cout<<"b1: "<<b1<<"b2: "<<b2<<endl;
        return -1;
    }
    
    if(albero.radice() == true)
        return 1 + b1;
    else
        return b1;
}

int main()
{

    AlberoB<bool>uno(true);
    
    AlberoB<bool>due(true);
    AlberoB<bool>tre(true);
   
    AlberoB<bool>quattro(true);
    AlberoB<bool>cinque(true);
    
    AlberoB<bool>sei(true);
    AlberoB<bool>sette(true);

    AlberoB<bool>otto(true);
    AlberoB<bool>nove(true);
    
    uno.insFiglio(SIN,due);
    uno.insFiglio(DES,tre);
    
    due.insFiglio(SIN,quattro);
    due.insFiglio(DES,cinque);

    tre.insFiglio(SIN,sei);
    tre.insFiglio(DES,sette);

    sei.insFiglio(SIN,otto);
    sei.insFiglio(DES,nove);


    if(countTrue(uno)==-1)
        cout<<"NO";
    

    return 0;
}