#include<iostream>
#include "Grafo.hpp"
#include <vector>
using namespace std;

int nCitta = 4;

void add(vector<int>& sol,int x) {
    sol.push_back(x);
    
}

void remove(vector<int>& sol,int x) {
    sol.pop_back();

}

bool presente(vector<int>& sol, int x) {
    for(int i = 0; i < sol.size(); i++) {
        if(sol[i] == x)
        return true;
    }
    return false;
}

bool adiacenti(const Grafo& g, int x, vector<int>& sol) {

    for(int i = 0; i < sol.size(); i++) {
        if(g(sol[i],x)) {
            return true;
        }
    }
    return false;
}

bool canAdd(vector<int>& sol, int x, const Grafo& g, int k) {



    if(!presente(sol,x) && !adiacenti(g,x,sol) && sol.size() < k)
    return true;

    return false;
        

}

bool isComplete(vector<int>& sol, const Grafo& g) {

    bool citta [4] = {false};

    for(int i = 0; i < sol.size(); i++) {
        citta[sol[i]] = true;
    }

    for(int i = 0; i < 4; i++) {
        if(!citta[i]) {
            if(adiacenti(g, i, sol))
            citta[i] = true;
        }
        
    }

    for(int i = 0; i < 4; i++) {
        if(!citta[i])
        return false;
    }

    return true;



}

bool solve(vector<int>& sol, const Grafo& g, int k) {

    int x = 0;

    while(x < 4) {

        if(canAdd(sol,x,g,k)) {
             add(sol,x);
       
        
        if(isComplete(sol,g)) {

            return true;
        }
        else if(solve(sol,g,k))
            return true;

            remove(sol,x);
            x++;  
        } 
        else  
            x++;       
        
    }
    return false;
}

int main() {

    vector<string> citta = {"Xinghua", "Modiin", 
                            "Apas", "Ukiah"};

    Grafo g(4);
    
    g(0,1,true);
    g(1,2,true);
    g(1,0,true);
    g(2,1,true);


    vector<int> cittaConSerbatoio;
    
    int k = 0;//serve per ottimizzare

    while(k <=3) {
        if(solve(cittaConSerbatoio,g,k)) {
            for(int i = 0; i < cittaConSerbatoio.size(); i++) 
                cout << citta[cittaConSerbatoio[i]] << " ";
                return 0;
        }

        k++;
    }

    cout << "Nessuna sol";
    return 0;
 
}