#include"AlberoB.h"
//  #include"UtilAlbero.h"
#include<iostream>
#include<list>
using namespace std;

int Max(int x,int y)    {   return x>y; }

int profondita(AlberoB<int> A)
{
    if(A.nullo())
        return 0;

    int p1 = 0, p2 = 0;

    p1 = profondita(A.figlio(SIN));
    p2 = profondita(A.figlio(DES));

    return 1 + Max(p1,p2);
}


void visitaAnticipata(AlberoB<int> A)           // OK FUNZIONA
{
    if(!A.nullo())
    {
        cout<<A.radice();
        visitaAnticipata(A.figlio(SIN));
        visitaAnticipata(A.figlio(DES));
        
    }
}

void visitaInfissa(AlberoB<int> A,list<int> lista)      
{
    if(!A.nullo())
    {
        visitaInfissa(A.figlio(SIN),lista);
        lista.push_back(A.radice());
        visitaInfissa(A.figlio(DES),lista);

    }
}   

int main()
{
    AlberoB<int> A(1);
    AlberoB<int> B(4);
    AlberoB<int> C(5);
    AlberoB<int> D(9);
    AlberoB<int> E(11);

    A.insFiglio(SIN,B);
    A.insFiglio(DES,C);

    D.insFiglio(SIN,E);


    cout<<profondita(A)<<endl;

    visitaAnticipata(A);

    /*
    list<int> L;
    visitaInfissa(A,L);

    cout<<L.size();

    for(auto i=L.begin();i!=L.end();i++)
        cout<<(*i)<<" ";    */



    // E' tutto giusto mi da un problema con la classe AlberoB 
    

    return 0;
}
