#include"AlberoB.h"
#include<iostream>
#include<list>
#include<string>
using namespace std;


int sommaNodi(const AlberoB<int>& A)
{
    // Scrivere una funzione che preso in input un ALberoB<int> restituisca a somma dei suoi nodi 

    if(A.nullo())
        return 0;

    return A.radice() + sommaNodi(A.figlio(SIN)) + sommaNodi(A.figlio(DES));
}

bool determinaProprieta(const AlberoB<int>& A)
{
/*  Scrivere una funzione che preso in input un AlberoB<int> determini se
    tutti i nodi hanno il valore maggiore della somma dei sotto alberi sinistri e
    destri. 

                    42                                                                                          4
            20              12                                                                            2             1
                        4        2                                                                                       8

        42 > 20 + 12 + 4 + 2                                                                               4 > 2 + 1 + 8 FALSE
        20 > 0 ( perche' non ci sono figli )
        12 > 4 + 2
        4 > 0
        2 > 0           TRUE
*/

    if(A.nullo())
        return true;

    int l=0,r=0;

    if(!A.figlio(SIN).nullo())
        l = A.figlio(SIN).radice();
    if(!A.figlio(DES).nullo())
        r = A.figlio(DES).radice();

    return ( (A.radice() > l+r) && determinaProprieta(A.figlio(SIN)) && determinaProprieta(A.figlio(DES)) );
}


bool piramideSalda(const AlberoB<int>& A,const int& PESOMAX)
{
    /*   Si consideri un albero che rappresenti una piramide di persone. Si vuole
        determinare se la piramide è salda, cioè, supponendo di memorizzare per
        ciascun nodo dell’albero il peso della persona, il peso complessivo di
        ciascun livello della piramide non deve eccedere un certo peso PESOMAX.
        Scrivere una funzione che ricevuto un albero binario di “pesi” (cioè di
        interi) restituisca true se la piramide è salda.
        Si può assumere che tutti i livelli dell’albero siano pieni  
        
        Dato un certo PESOMAX, la somma dei valore per ogni livello deve essere <= PESO MAX 
        
        

                    42                                                                                          10
            6                   12                                                                          8       3
        4       3           8       2
        
        PESOMAX = 80                                                                                      PESOMAX = 10 
        LIVELLO 1 : SOMMA = 42 <= PESOMAX                                                                 LIVELLO 1 : SOMMA = 10 <= PESOMAX
        LIVELLO 2 : SOMMA = 6 + 12 <= PESOMAX                                                             LIVELLO 2 : SOMMA = 8 + 3 > PESO MAX  FALSE 
        LIVELLO 3 : SOMMA = 4+3+8+2 <= PESO MAX   TRUE 
        
        */

       bool salda = true;

       if(!A.nullo())
       {
           list<AlberoB<int>>   coda;   // Coda dei nodi    [10, 8, 3]
           coda.push_back(A);            

            list<int> codaLivelli;      // Coda dei livelli     [ 1, 2, 2]
            codaLivelli.push_back(1);

            int livelloPrecedente = 0, livelloCorrente = 0, somma = 0;

            while(!coda.empty())
            {
                AlberoB<int> tmp = coda.front();         // Accedo alla testa della coda
                coda.pop_front();                        // Elimino l'elemento in testa alla coda

                livelloCorrente = codaLivelli.front();
                codaLivelli.pop_front();

                if(livelloPrecedente == livelloCorrente)        // Ho estratto dalla coda un nodo allo stesso livello
                    somma += tmp.radice();
                else
                {
                    if(somma > PESOMAX)
                        return false;

                    livelloPrecedente = livelloCorrente;           // Ho estratto un nodo che non fa parte dello stesso livello -> cambio livello
                    somma = tmp.radice();
                }
                


                if(tmp.figlio(SIN).nullo())
                {
                    coda.push_back(A.figlio(SIN));      // Aggiungo il figlio SIN alla coda
                    codaLivelli.push_back(livelloCorrente + 1);
                }
                if(tmp.figlio(DES).nullo())
                {            
                    coda.push_back(A.figlio(DES));      // Aggiungo il figlio DES alla coda 
                    codaLivelli.push_back(livelloCorrente + 1);
                }

                if( somma > PESOMAX)
                    return false;
           }
        }

       return true;
}

struct Dipendente
{
    int cod;
    string name;
    Dipendente(int c,string n) : cod(c), name(n) { }
};

int contaSottoposti(const AlberoB<Dipendente>& A)
{
    if(A.nullo())
        return 0;

    int sottopostiSin = contaSottoposti(A.figlio(SIN));
    if(!A.figlio(SIN).nullo())
        sottopostiSin = sottopostiSin + 1;          // +1 indica che sto contando nel contegigo anche A.figlio(SIN)
    int sottopostiDes = contaSottoposti(A.figlio(DES));
        if(!A.figlio(DES).nullo())
        sottopostiDes = sottopostiDes + 1;          // +1 indica che sto contando nel contegigo anche A.figlio(SIN)

    return sottopostiSin + sottopostiDes;
}

void promozione(const AlberoB<Dipendente>& A,list<Dipendente>& daPromuovere)
{
    /* La struttura organizzativa di una compagnia è rappresentata da un albero
       binario di Dipendenti. In particolare, dato un dipendente D, i dipendenti
       compresi nel sottoalbero di cui D è radice sono suoi sottoposti. Scrivere
       una funzione che ricevuto un albero di dipendenti, restituisca la lista dei
       dipendenti “da promuovere”, cioè di quei dipendenti che hanno più di 10
       sottoposti.
       Restituire i nodi che abbiano più di 10 sotto alberi         */

    if(!A.nullo())
    {
        if(contaSottoposti(A) > 10)
        {
            daPromuovere.push_back(A.radice());
            promozione(A.figlio(SIN),daPromuovere);
            promozione(A.figlio(DES),daPromuovere);
        }
    }

}




int main()
{
    AlberoB<int> A(12);
    AlberoB<int> B(4);
    AlberoB<int> C(2);
    AlberoB<int> D(200);

    A.insFiglio(SIN,B);
    A.insFiglio(DES,C);
    C.insFiglio(SIN,D);


    if(determinaProprieta(A))
        cout<<"OK"<<endl;
    else
        cout<<"OH NO"<<endl;
    
    
    return 0;
}