#include<iostream>
#include"AlberoB.h"
#include<list>
#include<queue>
#include"mainAlbero.cpp"
using namespace std;

/*
    Negli alberi generali sono rilevanti quattro tipi di visita:
    (i)	visita anticipata, in cui viene prima visitata la radice e poi i due sottoalberi;
    (ii) visita posticipata, in cui vengono visitati i due sottoalberi e poi la radice;
    (iii) visita infissa in cui viene visitato prima il sottoalbero di sinistra, poi la radice e infine il sottoalbero di destra
    (iv) visita per livelli, in cui viene visitata la radice (nodo di livello 1), poi i nodi di livello 2 e così via fino ai nodi dell'ultimo livello.
*/

template<class T>          // OK FUNZIONA CORRETTAMENTE
void visitaInfissa(const AlberoB<T>& A,list<T>& lista)  // 4, 2, 5, 1, 8, 6, 3, 9, 7    SOTTOALBERO_SX -> RADICE -> SOTTOALBERO_DX
{                                                                                    // ( DAL BASSO )               ( DAL BASSO )
    
    if(!A.nullo())
    {
        visitaInfissa(A.figlio(SIN),lista);
        lista.push_back(A.radice());
        visitaInfissa(A.figlio(DES),lista);
    }
}

template<class T>       // OK FUNZIONA CORRETTAMENTE 
void visitaPosticipata(const AlberoB<T>& A,list<T>& lista)  // 4, 5, 2, 8, 6, 9, 7, 3, 1    SOTTOALBERO_SX -> SOTTOALBERO_DX -> RADICE
{                                                                                         // ( DAL BASSO )     ( DAL BASSO )
    
    if(!A.nullo())
    {
        visitaPosticipata(A.figlio(SIN),lista);
        visitaPosticipata(A.figlio(DES),lista);
        cout<<A.radice()<<" ";
    }
}



template<class T>       // OK FUNZIONA CORRETTAMENTE
void visitaAnticipata(const AlberoB<T>& A)      // 1, 2, 4, 5, 3, 6, 8, 7, 9        RADICE -> SOTTOALBERO_SX -> SOTTOALBERO_DX
{                                                                                  //         ( DALL'ALTO )       ( DALL'ALTO )
    if(!A.nullo())
    {
        cout<<A.radice()<<" ";                      
        visitaAnticipata(A.figlio(SIN));
        visitaAnticipata(A.figlio(DES));
    }
}

// Ho provato a fare la visita per livelli ma non funziona, nemmeno modificando l'implementazione d
// di ricercaPerLivelli(A,x) di mainAlbero.cpp 


int main()
{
    AlberoB<int> radice(1);
    AlberoB<int> figlioS(2);
    AlberoB<int> figlioD(3);
    radice.insFiglio(SIN,figlioS);
    radice.insFiglio(DES,figlioD);

    AlberoB<int> A(4);
    AlberoB<int> B(5);
    figlioS.insFiglio(SIN,A);
    figlioS.insFiglio(DES,B);

    AlberoB<int> C(6);
    AlberoB<int> D(7);
    figlioD.insFiglio(SIN,C);
    figlioD.insFiglio(DES,D);

    AlberoB<int> E(8);
    C.insFiglio(SIN,E);

    AlberoB<int> F(9);
    D.insFiglio(SIN,F);

    cout<<"Visita Anticipata : dovrebbe stampare -> 1, 2, 4, 5, 3, 6, 8, 7, 9"<<endl;
    visitaAnticipata(radice);
    cout<<endl;


   
    list<int> L;    
    cout<<"Visita Infissa : dovrebbe stampare -> 4, 2, 5, 1, 8, 6, 3, 9, 7"<<endl;
    visitaInfissa(radice,L);
    for(auto x : L)
        cout<<x<<" ";
    cout<<endl;

    list<int> L1;    
    cout<<"Visita Posticipata : dovrebbe stampare -> 4, 5, 2, 8, 6, 9, 7, 3, 1"<<endl;
    visitaPosticipata(radice,L1);
    for(auto x : L1)
        cout<<x<<" ";
    cout<<endl;


    if(!ricercaPerLivelli(radice,8).nullo())
        cout<<"Ho trovato il numero 8!"<<endl;
    else
        cout<<"Non l'ho trovato"<<endl;
    
    
    
    


    return 0;
}