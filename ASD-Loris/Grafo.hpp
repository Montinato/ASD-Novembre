#ifndef GRAFO_H_
#define GRAFO_H_

#include <cassert>
#include <vector>

// equivale ad usare un typedef
using boolVec = std::vector<bool>;  //tutti i vector che all interno hanno dei bool si chiameranno boolVec => a typedef

//grafo orientato i cui nodi sono interi
class Grafo {
protected:
    // numero di nodi, numero di archi
    unsigned vn = 0, vm = 0; 
    
    // matrice di adiacenza
    std::vector<boolVec> archi; 

    // inizializza la matrice di adiacenza
    void init(unsigned n) {
        this->vn = n;
        this->vm = 0;

        this->archi = std::vector<boolVec>(n);
        for (unsigned i = 0; i < n; i++)
            this->archi[i] = boolVec(n, false);
    }

public:
    // grafo con n nodi, indicizzati da 0 a n-1
    Grafo(unsigned n) { //n = numero di nodi del grafo
        assert(n >= 1);
        this->init(n);
    }

    // inserisce o elimina l'arco (i,j) (a seconda del valore di b)
    //grafo g, g(i,j,true)=>crea un arco se non esiste da i a j false lo elimina
    void operator()(unsigned i, unsigned j, bool b) {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        bool esisteArco = this->archi[i][j];
        if ((!esisteArco && b) || (esisteArco && !b)) {
            this->archi[i][j] = b;  // arco i->j
            if (b)
                vm++;//incremento di uno il numero di archi correnti nel grafo
            else
                vm--;//decremento di uno il numero di archi correnti nel grafo
        }
    }

    // elimina tutti gli archi
    void svuota() {
        for (unsigned i = 0; i < this->n(); i++)
            for (unsigned j = 0; j < this->n(); j++)
                archi[i][j] = false;
        vm = 0;//numero archi correnti nel grafo
    }

    Grafo& operator=(const Grafo& g) {
        if (this == &g)
            return *this;
        this->init(g.n());
        for (unsigned i = 0; i < this->n(); i++)
            for (unsigned j = 0; j < this->n(); j++)
                if (g(i,j))
                    this->archi[i][j] = true;
                else
                    this->archi[i][j] = false;
        return *this;
    }

    
    unsigned n() const { return vn; }
    unsigned m() const { return vm; }
    // true se l'arco (i,j) esiste, altrimenti false
    //grafo g, g(i,j) true se esiste un arco tra i e j
    bool operator()(unsigned i, unsigned j) const {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        return this->archi[i][j];
    }
};

#endif