//I/P:govardhan is my bestfriend
//O/P:aadghnorv is my bdeefinrst 


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void find(string g)
{
    vector<string> res;
    vector<string> finalres;
    string temp="";
    int n=g.size();
    for(int i=0;i<n;i++)
    {
        if(isspace(g[i]))
        {
            res.push_back(temp);
            temp="";
        }
        else
        {
            temp=temp+g[i];
        }
    }
    res.push_back(temp);
    for(auto it:res)
    {
        sort(it.begin(),it.end());
        finalres.push_back(it);
    }
    for(auto it:finalres)
    {
        cout<<it<<endl;
    }
}
int main()
{
    string g;
    getline(cin,g);
    find(g);
    return 0;
}
