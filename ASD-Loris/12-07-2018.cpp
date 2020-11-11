#include<iostream>
#include<vector>
using namespace std;

class Indice {
    public:
        int i;
        int j;
};

int righe = 9;  
int colonne = 7;

bool verificaPicco(int m[9][7], int r, int c) {
 
    int somma = 0;
    int cont = 0;

    //sopra-sotto
    for(int i = r+1, j = r-1; (i < righe || j >= 0) && cont < 2; i++, j--) {

        if(i < righe)
        somma+=m[i][c];
    
        if(j >= 0) 
        somma+=m[j][c];

        cont++;
    }

    //cout << "somma sopra-sotto di " << r << " " << c <<" = " << somma << endl;

    cont = 0;

    //sinistra-destra
    for(int i = c+1, j = c-1; (i < colonne || j >= 0) && cont < 2; i++, j--) {

        if(i < colonne) 
        somma+=m[r][i];

        if(j >= 0) 
        somma+=m[r][j];

        cont++;

    }

    //cout << "somma destra-sinistra di " << r << " " << c <<" = " << somma << endl;

    cont = 0;

    //diagonale 
    for(int i = r+1, j = c+1; i < righe && j < colonne && cont < 1; i++, j++) {
        
        somma+=m[i][j];
        cont++;
    }

    cont = 0;
    for(int i = r-1, j = c-1; i >= 0 && j >= 0 && cont < 1; i--, j--) {
        
        somma+=m[i][j];
        cont++;
    }

    cont = 0;
    for(int i = r+1, j = c-1; i < colonne && j >= 0 && cont < 1; i++, j--) {
        
        somma+=m[i][j];
        cont++;
    }

    cont = 0;
    for(int i = r-1, j = c+1; i >= 0  && j < colonne && cont < 1; i--, j++) {
        
        somma+=m[i][j];
        cont++;
    }

    
       // cout << "somma diagonale di " << r << " " << c <<" = " << somma << endl;


    if(m[r][c] > somma) 
        return true;

    return false;
}

bool stessaDiagonale(vector<Indice>& picchi, int p1, int p2) {



     //diagonale 
    for(int i = picchi[p1].i+1, j = picchi[p1].j+1; i < righe && j < colonne; i++, j++) {
        if(picchi[p2].i == i && picchi[p2].j == j) {
            return true;
        }
    }

    for(int i = picchi[p1].i-1, j = picchi[p1].j-1; i >= 0 && j >= 0; i--, j--) {
        if(picchi[p2].i == i && picchi[p2].j == j) {
            return true;
        }
    }
  
    for(int i = picchi[p1].i+1, j = picchi[p1].j-1; i < righe && j >= 0; i++, j--) {
        if(picchi[p2].i == i && picchi[p2].j == j) {
            return true;
        }
    }

    for(int i = picchi[p1].i-1, j = picchi[p1].j+1; i >= 0 && j < colonne; i--, j++) {
        if(picchi[p2].i == i && picchi[p2].j == j) {
            return true;
        }
    }

    return false;
    
}

void eliminaPicco(int m[9][7], vector<Indice>& picchi) {

    bool maggioreTrovato = false;
    //verifica riga
    for(int i = 0; i < picchi.size(); i++) {
        for(int j = 0; j < picchi.size(); j++) {
            if(picchi[i].j == picchi[j].j && i != j) {
                if(m[picchi[i].i][picchi[i].j] > m[picchi[j].i][picchi[j].j])
                    picchi.erase(picchi.begin()+j);
            }
        }
    }

    //verifica colonna
      for(int i = 0; i < picchi.size(); i++) {
        for(int j = 0; j < picchi.size(); j++) {
            if(picchi[i].i == picchi[j].i && i != j) {
                if(m[picchi[i].i][picchi[i].j] > m[picchi[j].i][picchi[j].j])
                    picchi.erase(picchi.begin()+j);
            }
        }
    }

    //verifica diagonale
    for(int i = 0; i < picchi.size(); i++) {
        for(int j = 0; j < picchi.size(); j++) {
            if(stessaDiagonale(picchi,i,j)) {
                if(m[picchi[i].i][picchi[i].j] > m[picchi[j].i][picchi[j].j]) {
                    picchi.erase(picchi.begin()+j);
                }
            }
        }

    }

}

int main() {
    
    
    int m [9][7] =          {{3, 1, 3, 1, 1, 1, 1},
                             {2, 1, 2, 1, 2, 2, 1},
                             {1, 1, 1, 1, 18, 2, 1},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 2, 31, 2, 1, 1, 1},
                             {4, 1, 2, 1, 1, 2, 1},
                             {5, 4, 1, 2, 32, 1, 1},
                             {1, 6, 8, 5, 3, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1}};


    vector<Indice> picchi;

    for(int i = 0; i < righe; i++) {
        for(int j = 0; j < colonne; j++) {
            if(verificaPicco(m, i, j)) {
                Indice ind;
                ind.i = i;
                ind.j = j;
                picchi.push_back(ind);
            }
        }
    }



    eliminaPicco(m,picchi);

    cout << "stampa picchi" << endl;
    for(int i = 0; i < picchi.size(); i++) {
        cout << picchi[i].i << " " << picchi[i].j << endl;
    }

}