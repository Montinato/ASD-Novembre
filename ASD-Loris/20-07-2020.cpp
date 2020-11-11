#include<iostream>
#include"AlberoB.h"
using namespace std;


int sommaDestra(const AlberoB<int> & a, int &somma)
{
    if(!a.nullo())
    {
        somma+=a.radice();
        
        if(!a.figlio(DES).nullo())
            sommaDestra(a.figlio(DES),somma);
    }
    return somma;
}

int sommaSinistra(const AlberoB<int> & a, int &somma)
{
    if(!a.nullo())
    {
        somma+=a.radice();
        
        if(!a.figlio(SIN).nullo())
            sommaSinistra(a.figlio(SIN),somma);
    }
    return somma;
}


int sommaTutti(const AlberoB<int> & a, int& sommaT)
{
    if(!a.nullo())
    {
        sommaT+=a.radice();
        if(!a.figlio(SIN).nullo())
        {
            sommaTutti(a.figlio(SIN),sommaT);
        }

        if(!a.figlio(DES).nullo())
        {
            sommaTutti(a.figlio(DES),sommaT);
        }
    }

}


int sommaIntASin(const AlberoB<int> & a, int& sommaT)
{

    if(!a.nullo())
    {
        if(!a.figlio(SIN).nullo())
        {
            sommaTutti(a.figlio(SIN), sommaT);
        }
    }
}

int sommaIntADes(const AlberoB<int> & a,int& sommaT)
{

    if(!a.nullo())
    {
        if(!a.figlio(DES).nullo())
        {
            sommaTutti(a.figlio(DES), sommaT);
        }
    }
}

int sommaInterniDestra(const AlberoB<int> & a,int& sommaT)
{
    if(!a.nullo())
    {
        if(!a.figlio(DES).nullo())
        {
            sommaIntASin(a.figlio(DES),sommaT);
        }
            sommaInterniDestra(a.figlio(DES),sommaT);

    }
    return sommaT;
}

int sommmaInterniSinistra(const AlberoB<int> & a,int& sommaT)
{
    if(!a.nullo())
    {
        if(!a.figlio(SIN).nullo())
        {
            sommaIntADes(a.figlio(SIN),sommaT);
        }
            sommmaInterniSinistra(a.figlio(SIN),sommaT);
    }
    return sommaT;
}


int main()
{

    AlberoB<int> a(4);
    AlberoB<int> b(3);
    AlberoB<int> c(2);

    AlberoB<int> d(8);
    AlberoB<int> e(1);
    
    AlberoB<int> f(8);
    AlberoB<int> g(4);
    AlberoB<int> h(4);
    AlberoB<int> k(2);

    a.insFiglio(SIN,b);
    a.insFiglio(DES,c);

    b.insFiglio(SIN,d);
    c.insFiglio(DES,e);

    c.insFiglio(SIN,f);
    f.insFiglio(SIN,g);
    f.insFiglio(DES,h);
    d.insFiglio(DES,k);

        
    int somma1=0;
    int somma2=0;
    //cout<<sommaDestra(a,somma1)<<endl;
    //cout<<sommaSinistra(a,somma2);

    int sommaT=0;

    sommaInterniDestra(a,sommaT);
    sommmaInterniSinistra(a,sommaT);


    if(sommaDestra(a,somma1)+sommaSinistra(a,somma2)-a.radice()==sommaT)
    {
        cout<<"OK";
    }
    else
    {
        cout<<"NO";
    }
    

    return 0;
}