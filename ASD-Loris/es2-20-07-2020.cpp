#include<iostream>
#include<vector>
using namespace std;
                    //  0           1       2           3           4           5       6
vector<vector<int>> I={{4,-3,2},{11,42,-3},{-3,2,11},{88,11,4},{4,-3,2,11,42},{88,4,8},{2}};
int q=3;


bool canAdd(int x, vector<int>  & sol)
{
    for(int i=0;i<I[x].size(); i++)
        for(int j=0; j<sol.size(); j++)
            for(int k=0; k<I[sol[j]].size(); k++)
                if(I[x][i]==I[sol[j]][k])
                    return false;



                    return true;


}

void add(int x, vector<int> & sol)
{
    sol.push_back(x);
}

bool isComplete(vector<int> & sol)
{
    if(sol.size()==q)
        return true;
        
    return false;
}

void remove(int x, vector<int> & sol)
{
    sol.pop_back();
}

int next(int x)
{

    return x+1;

}

bool solve(vector<int>  & sol) 
{
   int x = 0;
    while (x < I.size()) 
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
    vector<int> sol;

    if(solve(sol))
    {
        cout<<"Ho trovato una soluzione\n";

        for(int i =0; i<sol.size(); i++)
        {
            for(int j=0;j<I[sol[i]].size(); j++)
                cout<<I[sol[i]][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO";
    }
    

    return 0;
}