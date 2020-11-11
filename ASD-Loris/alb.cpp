#include<iostream>
#include"AlberoB.h"

using namespace std;

int somma(int &s, const AlberoB<int> & a)
{
    s+=a.radice();
    cout<<s<<endl;

    
    if(!a.figlio(SIN).nullo())
         somma(s,a.figlio(SIN));

    if(!a.figlio(DES).nullo())
         somma(s,a.figlio(DES));
    
return s;
}

bool verifica( const AlberoB<int> &a)
{
    int somFig;
    int s2=0;
    somFig= somma(s2,a);
    if(a.radice()<=(somFig-a.radice()))
        return false;
    if(!a.figlio(SIN).nullo())
        verifica(a.figlio(SIN));

    if(!a.figlio(DES).nullo())
        verifica(a.figlio(DES));
    return true;
}

int main()
{
    AlberoB<int> a(11);
    AlberoB<int> b(1);
    AlberoB<int> c(6);
    AlberoB<int> d(3);

    a.insFiglio(SIN,b);
    a.insFiglio(DES,c);
    c.insFiglio(DES,d);
    int s=0;

    cout<<somma(s,a);

    if(verifica(a))
    cout<<"OK";

    return 0;
}