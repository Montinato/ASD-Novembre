#include"AlberoB.h"
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int max(int x,int y)
{
	return x>y;
}

int profondita(AlberoB<int> A)
{
	if(A.nullo())
		return 0;
	else
	{
		int p1=0,p2=0;

		p1 = profondita(A.figlio(SIN));
		p2 = profondita(A.figlio(DES));

		return 1 + max(p1,p2);

	}
	
}

// Versione poco efficiente
bool bilanciato(AlberoB<int> A)
{
	if(A.nullo())
		return true;
	
	return ((abs(profondita(A.figlio(SIN))) - abs(profondita(A.figlio(DES))) <=1) && (bilanciato(A.figlio(SIN)) && bilanciato(A.figlio(DES))));
}

// Versone piu' efficiente

bool bilanciatoProfondo(AlberoB<int> A,int& p)
{
	if(A.nullo())
		return true;
	else
	{
		int p1=0,p2=0;

		bool b1 = bilanciatoProfondo(A.figlio(SIN),p1);
		bool b2 = bilanciatoProfondo(A.figlio(DES),p2);
		p = max(p1,p2) + 1;

		return (b1 && b2 && (abs(p2) - abs(p1) <= 1));
	}
	
}


void visitaInfissa(const AlberoB<int> A,list<int>& L)
{
	if(!A.nullo())
	{
		visitaInfissa(A.figlio(SIN),L);
		L.push_back(A.radice());
		visitaInfissa(A.figlio(DES),L);
	}
}

bool ricerca(AlberoB<int> A,int value)
{
	if(A.nullo())
		return false;
	
	list<int> lista;

	visitaInfissa(A,lista);

	for(auto i=lista.begin();i!=lista.end();i++)
	{
		if((*i) == value)
			return true;
	}

	return false;
}