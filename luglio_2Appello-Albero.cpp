#include"AlberoB.h"
#include"mainAlbero.cpp"
#include"FunzioniAlbero.cpp"
#include<list>
#include<iostream>
using namespace std; 

list<int> estremi(AlberoB<int>& A)
{
    list<int> estremi;

    AlberoB<int> temp = A;

    estremi.push_back(temp.radice());
    
    while(true)
    {
        estremi.push_back(temp.figlio(SIN).radice());
        temp = temp.figlio(SIN);

        if(temp.foglia())
            break;
    }

    temp = A;

    while(true)
    {
        estremi.push_back(temp.figlio(DES).radice());
        temp = temp.figlio(DES);

        if(temp.foglia())
            break;
    }
    

    for(auto x : estremi)
        cout<<x<<endl;


    return estremi;
}

bool esercizio1(AlberoB<int>& A)
{
    int sommaLiberi = 0;
    int sommaVincolati = 0;
    int sommaTotale = 0;

    list<int> ex = estremi(A);
    for(auto x : ex)
        sommaVincolati += x;

    sommaTotale = sommaNodi(A);
    
    cout<<"Somma Vincolati: "<<sommaVincolati<<endl;

    sommaLiberi = sommaTotale - sommaVincolati;

    cout<<"Somma Liberi: "<<sommaLiberi<<endl;

    return sommaLiberi == sommaVincolati;
    
}

int main()
{
    AlberoB<int> A(4);

    AlberoB<int> B(3);
    AlberoB<int> C(2);

    A.insFiglio(SIN,B);
    A.insFiglio(DES,C);

    AlberoB<int> D(6);
    B.insFiglio(SIN,D);

    AlberoB<int> E(8);
    AlberoB<int> F(1);
    C.insFiglio(SIN,E);
    C.insFiglio(DES,F);

    AlberoB<int> G(4);
    AlberoB<int> H(4);

    
    E.insFiglio(SIN,G);
    E.insFiglio(DES,H);


   // prefix(A);



    if(esercizio1(A))
        cout<<"SIUUUU";
    else
        cout<<"OH NO";  
    
    return 0;
}