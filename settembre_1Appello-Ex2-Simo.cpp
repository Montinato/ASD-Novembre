#include<iostream>
#include<vector>
using namespace std;
int val(string s)
{
    if(s=="ab")
     return 11;
    if(s=="cdc")
     return 11;
    if(s=="xyz")
        return 12;
    if(s=="q")
        return 8;
    if(s=="q42")
        return 7;
    if(s=="8a8b")
        return 34;
return 23;
}

void add(int x,vector<string>&S, vector<string>& S1,vector<string>& S2)
{
    if(S1.empty())
    {
        S1.push_back(S[x]);
        return;
    }
    if(S2.empty())
    {
        S2.push_back(S[x]);
        return;
    }
    int somma=0;
    int somma1=0;
    for(int i=0;i<S1.size();i++)
    {
        somma=somma+val(S1[i]);
    }
    for (int i=0; i<S2.size(); i++)
    {
        somma1 = somma1 + val(S2[i]);
    }
    if(somma>=somma1)
    {
        
        S2.push_back(S[x]);
        return;
    }
    else
    {
        S1.push_back(S[x]);
        return;
    }
    
}
bool isComplete(vector<string>& S1, vector<string>& S2)
{
    int somma=0;
    int somma1=0;
    for (int i=0;i<S1.size();i++)
    {
        somma=somma+val(S1[i]);
    }
    for (int i=0; i<S2.size();i++)
    {
        somma1 = somma1 + val(S2[i]);
    }
    if(somma==somma1 && S1.size()>1 && S2.size()>1)
        return true;

return false;
}
void remove(int x,vector<string>& S1,vector<string>& S2,vector<string> S)
{
    for(int i=0;i<S1.size();i++)
    {
        if(S[x]==S1[i])
            S1.pop_back();
    }
    for (int i=0; i<S2.size();i++)
    {
        if (S[x] == S2[i])
            S2.pop_back();
    }
}
bool canAdd(int x,vector<string> S,vector<string> S1, vector<string> S2)
{
    int cont=0;
    int contS=0;
    for (int i= 0; i < S1.size(); i++)
    {
        if (S[x] == S1[i])
            cont++;
    }
    for (int i = 0; i < S2.size(); i++)
    {
        if (S[x] == S2[i])
            cont++;
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (S[x] == S[i])
            contS++;
    }
    
   if(cont<contS) 
    return true; 
 return false;
}
bool backtracking(vector<string> S, vector<string>& S1, vector<string>& S2)
{
    int x = 0;
    
while (x <= S.size())
{
    if(canAdd(x,S,S1,S2))
     {
        add(x, S,S1,S2);
        if(isComplete(S1,S2))
            return true;
        else if (backtracking(S,S1,S2))
            return true;
        remove(x,S1,S2,S);
        x++;
     }
    else
    {
        x++;
    }
    
    
}
return false;
}
int main(){

vector<string> S;
vector<string> S1;
vector<string> S2;
string a;
a="ab";
S.push_back(a);
a="cdc";
S.push_back(a);
a="xyz";
S.push_back(a);
a="q";
S.push_back(a);
a="q42";
S.push_back(a);
a="8a8b";
S.push_back(a);
a="ccc";
S.push_back(a);

if(backtracking(S,S1,S2))
{
    cout<<"SEMBRA FUNZIONARE"<<endl;

}
else
{
    cout<<"NON FUNZIONA"<<endl;
}
cout<<"S1"<<endl;
for (int i = 0; i < S1.size(); i++)
{
    cout<<S1[i]<<endl;
}
cout<<"S2"<<endl;
for (int i = 0; i < S2.size(); i++)
{
    cout<<S2[i]<<endl;
}
cout<<"FINE"<<endl;

}