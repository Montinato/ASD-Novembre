#include"AlberoB.h"
#include"mainAlbero.cpp"
#include<iostream>
using namespace std;

bool checkRadice(AlberoB<bool>& A)
{
    return A.radice();
}

bool checkFoglia(AlberoB<bool>& A)
{
    if(A.foglia())
    {
        if(A.radice())
        
    }
}




int main()
{
    
    AlberoB<bool> A(false);         // radice

    AlberoB<bool> B(true);
    AlberoB<bool> C(true);
    A.insFiglio(SIN,B);
    A.insFiglio(DES,C);

    AlberoB<bool> D(true);
    AlberoB<bool> E(true);
    B.insFiglio(SIN,D);
    B.insFiglio(DES,E);

    AlberoB<bool> F(true);
    AlberoB<bool> G(false);
    C.insFiglio(SIN,F);
    C.insFiglio(DES,G);





    return 0;
}