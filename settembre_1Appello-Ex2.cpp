#include<string>
#include<iostream>
#include<vector>
using namespace std;

int val(string& s)
{
    if(s == "ab")
        return 11;
    
    if(s == "cde")
        return 11;
    
    if(s == "xyz")
        return 12;
    
    if(s == "q")
        return 8;
    
    if(s == "q42")
        return 7;
    
    if(s == "8a8b")
        return 34;
    
    if(s == "ccc")
        return 23;
    
    return -1;
}

// BHO 
bool bt(vector<string>& S,vector<string>& S1,vector<string>& S2)
{
    int x = 0;

    while(x != S.size())
    {
        if(canAdd(x,S,S1,S2))
        {
            add(x,S)
        }
    }

}

int main()
{
    vector<string> S;
    int sommaS = 0,somma = 0;


    S.push_back("ab");  S.push_back("cde"); S.push_back("xyz"); S.push_back("q");   S.push_back("q42");    
    S.push_back("8a8b");  S.push_back("ccc");


    /*  for(auto elem : S)
        sommaS+=val(elem);
    cout<<sommaS; */


    return 0;
}