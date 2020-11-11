#include <iostream>
#include "AlberoB.h"
#include<queue>
#include<vector>
using namespace std;


int somma_=0;


void somma (const AlberoB<int>& a, int&  somma_)
{
	
    if (!a.nullo())
	{
		somma_+= a.radice();
		somma(a.figlio(DES), somma_);
		somma(a.figlio(SIN), somma_);
	}	
}


int livello = 1;
int help = 2;
int cont = 0;



bool verificaPeso(const AlberoB<int> & a, int pesoMax)
{
    queue<AlberoB<int>> coda;


    coda.push(a);



int sommaPesi = 0;



    while(!coda.empty()) 
    {
        AlberoB<int> daValutare = coda.front();
        coda.pop();
        cout << daValutare.radice() << endl;



        sommaPesi+=daValutare.radice();
            
        if(!daValutare.figlio(SIN).nullo()) {
            coda.push(daValutare.figlio(SIN));
            
           
            
          
        }


         if(!daValutare.figlio(DES).nullo()) {
            coda.push(daValutare.figlio(DES));
            
            cont++;
           
            if( cont == help - 1) {
          
            
            help *=2;
           
            cout << "Somma livello numero:  " << livello++ << " = : " << sommaPesi << endl;
            if(sommaPesi > pesoMax) {
                return false;
            }
           
             sommaPesi = 0;
           
           
            }



        }      


    }


        cout << "Somma livello numero:  " << livello++ << " = : " << sommaPesi << endl;



        if(sommaPesi > pesoMax)
           return false;


    return true;
}

void bilanciato(const AlberoB<int> & a)
{

	if(a.nullo())
		return false;

    queue<AlberoB<int>>coda;
    queue<int> livelli;

    int livelloPrecedente=0;
    int livelloCorrente=0;
    int somma=0;


	coda.push(a);
	livelli.push(1);

	while(!coda.empty())
	{
		AlberoB<int> daValutare= coda.front();
		coda.pop();

		livelloCorrente=livelli.front();

		if(livelloCorrente==livelloPrecedente)
		{
			somma+=daValutare.radice();
		}
		else
		{
			if(somma>pesoMax)
				return false;
				

			livelloPrecedente=livelloCorrente;
			somma=daValutare.radice();
		}


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


		if(somma>pesoMax)
			return false;


	}
	return true;

}



void verifica(const AlberoB<int> & a)
{

    vector<AlberoB<int>>coda;
	coda.push_back(a);
	bool ok=true;
	int i=0;
	
	while(ok)
	{
		AlberoB<int> daValutare= coda[i];

		if(!coda[i].figlio(SIN).nullo())
		{
			coda.push_back(coda[i].figlio(SIN));
			coda.push_back(coda[i].figlio(DES));
		}
		else
			ok=false;

        i++;
	}

    
    for(int k=0; k<coda.size(); k++)
    {
        cout<<coda[k].radice()<<" - ";
    }

}

int main()
{


    int pesoM = 11;


    cout << "inserisci peso max: ";
   




   AlberoB <int> A(10);
    AlberoB <int> B(15);
    AlberoB <int> C(20);


    AlberoB <int> D(2);
    AlberoB <int> E(4);


    AlberoB <int> F(10);
    AlberoB <int> G(5);
 
    A.insFiglio(SIN,B);
    A.insFiglio(DES,C);


    B.insFiglio(SIN, D);
    B.insFiglio(DES, E);


    C.insFiglio(SIN, F);
    C.insFiglio(DES, G);


    //cout<<verificaPeso(A, pesoM);
    
 //   somma(A,somma_);
   // cout<<somma_;

    verifica(A);


}