#include<iostream>
#include "Grafo.hpp"
#include<vector>

using namespace std;

class Corso {
    public:
        string nome;
        int ora;
};

string  nomeCorsi [] = {"ASD","PO","FOND","ARCH","DS"};
int ora [] = {10,14,17};
vector<Corso> possibiliOrari;

void riempiVettore() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            Corso c;
            c.nome = nomeCorsi[j];
            c.ora = ora[i];
            possibiliOrari.push_back(c);
        }
    }
}

void add(vector<Corso>&sol, Corso &c) {
    sol.push_back(c);
}

void remove(vector<Corso>& sol) {
    sol.pop_back();
}

bool isComplete(vector<Corso>& sol) {
    return sol.size() == 5;
}

bool collegati(const Grafo& g, Corso& c1, Corso& c2) {

    int corso_1 = 0;
    for(int i = 0; i < 5; i++) {
        if(c1.nome == nomeCorsi[i]) {
            corso_1 = i;
            break;
        }
    }

    int corso_2 = 0;
    for(int i = 0; i < 5; i++) {
        if(c2.nome == nomeCorsi[i]) {
            corso_2 = i;
            break;
        }
    }

    for(int i = 0; i < g.n(); i++) {
        if(g(corso_1,corso_2))
            return true;
    }

    return false;
}

bool canAdd(vector<Corso>& sol, Corso& c, const Grafo& g) {
    
    //controllo se già presente
    for(int i = 0; i < sol.size(); i++) {
        if(sol[i].nome == c.nome)
            return false;
    }
   
    for(int i = 0; i < sol.size(); i++) {
        if(collegati(g,sol[i],c) && sol[i].ora == c.ora)
            return false;
    }

    return true;

}
    
bool solve(vector<Corso>& sol, const Grafo& g) {

    int x = 0;

    while(x < possibiliOrari.size()) {
        if(canAdd(sol,possibiliOrari[x],g)) {
           add(sol,possibiliOrari[x]);
        
        if(isComplete(sol)) {
            return true;
        }
        else if(solve(sol,g))
            return true;

        remove(sol);
            x++;  
        } 
        
         else  
         x++;       
               
    }
    return false;
}

int main() {

    riempiVettore();

    Grafo g(5);

    g(0,4,true);
    g(4,0,true);
    g(0,1,true);
    g(1,0,true);
    g(0,2,true);
    g(2,0,true);
    g(1,2,true);
    g(2,1,true);
    g(2,3,true);
    g(3,2,true);
    

    Grafo g2(4);
    
    g2(0,1,true);
    g2(1,0,true);
    g2(0,2,true);
    g2(2,0,true);
    g2(0,3,true);
    g2(3,0,true);
    g2(2,3,true);
    g2(3,2,true);
    g2(1,3,true);
    g2(3,1,true);
    g2(1,2,true);
    g2(2,1,true);  

    vector<Corso> sol;

    if(solve(sol,g)) {

        cout << "SI" << endl;
        for(int i = 0; i < sol.size(); i++) {
        cout << sol[i].ora << " " << sol[i].nome << endl;
        }
    }
    else {
        cout << "NO";
    }

    
}