#include<iostream>
using namespace std;
#include <list>

enum Direzione
{
    SIN = 0,
    DES = 1,
    CEN = 2
};

class Nodo
{
    private:
        int peso = 0;
        Nodo* padre=NULL;
        Nodo *dx = NULL;
        Nodo *sx = NULL;
        Direzione direzione=SIN;
        bool estremo=false;    
    public:
        Nodo(Nodo* p,Direzione d,int pa) {padre=p; direzione=d; peso=pa; setEstremo();}
        Nodo(Nodo d, Nodo s,int p) {*dx=d; *sx=s; peso=p;}
        Nodo* getDx() { return sx; }
        Nodo* getSx() { return dx; }
        int getPeso() { return peso; }
        void setDx(Nodo* n) {dx = n; }
        void setSx(Nodo* n){sx = n;}
        void setPeso(int x) { peso = x; }
        void setEstremo(){
            if(direzione==CEN) 
                {
                    estremo=true;
                    return;
                } 
            if((padre->getDirezione()==direzione || padre->getDirezione()==CEN) && padre->getEstremo()) 
                estremo=true;
                
        }
        bool getEstremo(){return estremo;}
        bool foglia(){ if (dx == NULL && sx == NULL) return true;return false;}
        Direzione getDirezione(){return direzione;}
        Nodo* getPadre(){return padre;}
};

class Albero
{
private:
    list<Nodo*> n;
    Nodo *curr = NULL;
    void setInizio()
    {
        for (list<Nodo*>::iterator it = n.begin(); it != n.end(); it++)
            if ((*it)->getDirezione() == CEN)
            {
                curr = *it;
            }
    }

public:
    Albero() {}
    Albero(list<Nodo *> n1)
    {
        n = n1;
        setInizio();
    }
    Nodo* figlio(Direzione d)
    {
        if (d == DES)
        {
            cout<<"CIOAOOA"<<endl;
            Nodo *n =curr->getDx();
            curr=curr->getDx();
            return n;
        }
        Nodo *n = curr->getSx();
        curr = curr->getSx();
        return n;
    }
    Nodo* padre()
    {
        Nodo *n=curr->getPadre();
        curr=curr->getPadre();
        return n;
    }
    int radice(){
        return curr->getPeso();
    }
    bool foglia(){
        return curr->foglia();
    }
};    

    int main()
    {
        Nodo *a = new Nodo(NULL, CEN, 4);
        Nodo *b = new Nodo(a, DES, 2);
        Nodo *c = new Nodo(a, SIN, 3);
        Nodo *d = new Nodo(c, SIN, 6);
        Nodo *e = new Nodo(b, DES, 1);
        Nodo *f = new Nodo(b, SIN, 8);
        Nodo *g = new Nodo(f, SIN, 4);
        Nodo *h = new Nodo(f, DES, 4);
        a->setDx(b);
        a->setSx(c);
        c->setDx(e);
        c->setSx(d);
        d->setDx(f);
        d->setSx(g);

        list<Nodo*> l;
        l.push_back(a);
        l.push_back(b);
        l.push_back(c);
        l.push_back(d);
        l.push_back(e);
        l.push_back(f);
        l.push_back(g);
        l.push_back(h);
        
        Albero al(l);
        
        int sommaE=0;
        int sommaNE=0;
        for(list<Nodo*>::iterator it=l.begin();it!=l.end();it++)
        {
            if((*it)->getEstremo())
            {
                sommaE=sommaE+(*it)->getPeso();
            }
            else
            {
                sommaNE=sommaNE+(*it)->getPeso();
            }
            
        }

        cout<<sommaNE<<endl;
        cout<<sommaE<<endl;
        
        return 0;
}