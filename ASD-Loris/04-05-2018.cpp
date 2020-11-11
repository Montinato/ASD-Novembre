#include<iostream>
#include<vector>
using namespace std;

class Posizione {
    public:
        int i;
        int j;
};

int m [6][6] = {{0,0,0,1,1,1},
               {0,0,0,1,1,1},
               {0,0,0,1,1,1},
               {2,2,2,3,3,3},
               {2,2,2,3,3,3},
               {2,2,2,3,3,3}};

int dimMatrice = 6;

vector<Posizione> indici;

int settori = 4;
int dimSettore = 3;
int t = 1;

void add(vector<Posizione>&sol, Posizione &p) {
    sol.push_back(p);
}

void remove(vector<Posizione>& sol) {
    sol.pop_back();
}

bool isComplete(vector<Posizione>& sol) {

    bool indice_settore [4] = {false};

    for(int s = 0; s < sol.size(); s++) {
        for(int i = 0; i < dimMatrice; i++) {
            for(int j = 0; j < dimMatrice; j++) {
                if(sol[s].i == i && sol[s].j == j) {
                    indice_settore[m[i][j]] = true;
                }
            }
        } 
    }

    for(int i = 0; i < 4; i++) {
        if(!indice_settore[i])
            return false;
    }

    return true;
}

bool canAdd(vector<Posizione>& sol, Posizione& p) {
    
    //ricerca su riga e colonna uguale
    for(int l = 0; l < sol.size(); l++) {
        if(sol[l].i == p.i || sol[l].j == p.j) 
            return false;
    }

    //ricerca nel settore
    int totSettore = (dimMatrice*dimMatrice)/settori;

    int valore = m[p.i][p.j];

    int help_l;
    int help_k;

    if(valore == 0) {
        help_l = dimSettore;
        help_k = dimSettore;
    }
    else if(valore == 1) {
        help_l = dimSettore;
        help_k = dimSettore*2;
    }
    else if(valore == 2) {
        help_l = dimSettore*2;
        help_k = dimSettore;
    }
    else if(valore == 3) {
        help_l = dimSettore*2;
        help_k = dimSettore*2;
    }

    bool almeno1 = false;
    for(int s = 0; s < sol.size(); s++) {
        for(int l = 0; l < help_l; l++) {
            for(int k = 0; k < help_k; k++) {
                if(sol[s].i == l && sol[s].j == k) 
                    almeno1 = true;
            }
        }
    }

    if(almeno1)
    return false;

    return true;

    
    
}

bool solve(vector<Posizione>& sol) {

    int x = 0;

    while(x < 36) {
       // cout << "x: " << x << endl;
        if(canAdd(sol,indici[x])) {
           add(sol,indici[x]);
        
        if(isComplete(sol)) {
            return true;
        }
        else if(solve(sol))
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
    
    for(int i = 0; i < dimMatrice; i++) {
        for(int j = 0; j < dimMatrice; j++) {
            Posizione p;
            p.i = i;
            p.j = j;
            indici.push_back(p);
        }
    }

    vector<Posizione> sol;

    if(solve(sol)) {
        cout << "OK";

        //stampa sol
        cout << "stampa sol: "<<endl;
        for(int i = 0; i < sol.size(); i++) {
            cout << sol[i].i << " " << sol[i].j << endl;
        }

        cout << "fine stampa sol" << endl;


        for(int s = 0; s < sol.size(); s++) {
            for(int i = 0; i < dimMatrice; i++) {
                for(int j = 0; j < dimMatrice; j++) {
                    if(sol[s].i == i && sol[s].j == j) {
                       m[i][j] = -1;
                    }
                }
            }
        }

        for(int i = 0; i < dimMatrice; i++) {
            for(int j = 0; j < dimMatrice; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NESSUNA SOLUZIONE";
    }

    return 0;
}
