#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> posizioni;

    int m [6][6] = {{0,0,0,1,1,1},
                {0,0,0,1,1,1},
                {0,0,0,1,1,1},
                {2,2,2,3,3,3},
                {2,2,2,3,3,3},
                {2,2,2,3,3,3}};

bool controllaSettore(int x, vector<int> & sol)
{
    int settore= m[posizioni[x].first][posizioni[x].second];
    //cout<<"settore di : "<<posizioni[x].first<<posizioni[x].second<<" "<<settore<<endl;

    for(int i=0; i<sol.size(); i++)
    {
        if(m [posizioni[sol[i]].first] [posizioni[sol[i]].second] == settore)
        {
            return false;//non posso agg alla sol quindi è presente in sol x
        }
    }

    return true;

}

bool controllaRiga(int x, vector<int> & sol)
{
    int riga=posizioni[x].first;

    for(int i=0; i<sol.size(); i++)
    {
        if(posizioni[sol[i]].first == riga)
        {
            return false;
        }
    }

    return true;
}

bool controllaColonna(int x, vector<int> & sol)
{
    int colonna=posizioni[x].second;

    for(int i=0; i<sol.size(); i++)
    {
        if(posizioni[sol[i]].second == colonna)
        {
            return false;
        }
    }

    return true;
}

bool canAdd(const int &x, vector<int> & sol)
{       

    if(controllaSettore(x,sol) && controllaRiga(x,sol) && controllaColonna(x,sol))
    {
        return true;
    }

    return false;

}

void add(const int &x, vector<int> & sol)
{
    sol.push_back(x);
}

bool controlloSettori(int x,vector<int> & sol)
{
    int settore= x;
    //cout<<"settore di : "<<posizioni[x].first<<posizioni[x].second<<" "<<settore<<endl;

    for(int i=0; i<sol.size(); i++)
    {
        if(m[posizioni[sol[i]].first][posizioni[sol[i]].second] == settore)
        {
            return false;//non posso agg alla sol quindi è presente in sol x
        }
    }

    return true;
}

bool isComplete(vector<int> &sol)
{

    for(int i=0; i<4; i++)
    {
        if(!controlloSettori(i,sol))
        {
            return false;
        }
    }
    return true;
}

void remove(const int & x,vector<int> & sol)
{
    sol.pop_back();
}

int next(int x)
{
    x=x+1;
    return x;    
}


bool solve(vector<int> &sol) 
{
    int x = 0;
    while (x < posizioni.size()) //posizioni.size()
    {
        if (canAdd(x,sol)) 
        {
            add(x,sol);
            if (isComplete(sol))
                return true;
        
            else if (solve(sol))
                return true;
            
            remove(x,sol);
        
            x = next(x);
        } 
    else
        x = next(x);
    }

return false;
}

int main()
{
    int dim=6;
    int settori=4;
    int dimSettori=3;
    int nTran=1;


   
    vector<int> sol;//posizione nel vector posizioni di x;

    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            posizioni.push_back(make_pair(i,j));
        }
    }

    if(solve(sol))
    {
        cout<<"OK"<<endl;
        for(int j=0; j<dim; j++)
        {
            cout<<posizioni[sol[j]].first<<" , "<<posizioni[sol[j]].second<<endl;
        }
    } 

    


    return 0;
}