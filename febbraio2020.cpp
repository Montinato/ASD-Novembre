#include"AlberoB.h"
#include"visiteAlberi.cpp"
#include<iostream>
using namespace std;

int main()
{
    // Primo Albero
    AlberoB<int> primo(0);
    AlberoB<int> p_sin(2);
    AlberoB<int> p_des(3);
    AlberoB<int> p_x(4);
    primo.insFiglio(SIN,p_sin);
    primo.insFiglio(DES,p_des);
    p_des.insFiglio(SIN,p_x);

    // Secondo Albero
    AlberoB<int> secondo(0);
    AlberoB<int> s_sin(1);
    AlberoB<int> s_y(2);
    secondo.insFiglio(SIN,s_sin);
    s_sin.insFiglio(DES,s_y);

    // Terzo Albero
    AlberoB<int> terzo(0);
    AlberoB<int> t_des(3);
    terzo.insFiglio(DES,t_des);


    int max = -100, min = 100;

    int first,second,third;

    first = profondita(primo);
    second = profondita(secondo);
    third = profondita(terzo);

    cout<<"Profondità primo: "<<first<<endl;
    cout<<"Profondità secondo: "<<" "<<second<<endl;
    cout<<"Profondità terzo: "<<" "<<third<<endl;


    // LA FUNZIONE E' GIUSTA , HO CONTROLLATO PIU' VOLTE 

    visitaPerLivelli(primo);
    
    return 0;
}