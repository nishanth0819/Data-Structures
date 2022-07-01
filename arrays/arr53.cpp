/*I/P:["abc","abcd","bc","adc"]
O/P:3
{"abc","abcd"} concadetaned string "abcabcd" can be rearranged as a palindrome "abcdcba"
{"abc","bc"} concadetaned string "abcbc" can be rearranged as a palindrome "bcacb"
{"abcd","adc"} concadetaned string "abcdadc" can be rearranged as a palindrome "acdbdca"
count=3

I/P:["eye","aa","c"] O/P:2
{"eye","aa"}-->"eayae"
{"aa","c"}-->"aca"
*/

//CODE:

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool ispalin(string g)
{
    map<char,int> mp;
    priority_queue<pair<int,char>> pq;
    int n=g.size();
    for(int i=0;i<n;i++)
         mp[g[i]]++;
    for(auto it:mp)
       pq.push({it.second,it.first});
    char g1[n];
    int i=0,j=n-1;
    int flag=0;
    while(pq.size()>1)
    {
        auto it=pq.top();
        pq.pop();
        if(it.first>=2)
        {
            g1[i]=it.second;
            g1[j]=it.second;
            i++;
            j--;
            it.first=it.first-2;
            if(it.first>0)
              pq.push({it.first,it.second});
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
       return false;
    else
       return true;
}
int find(vector<string> h)
{
    int n=h.size();
    int count=0;
    vector<vector<int>> vis;
    vis.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j || vis[i][j]==1)
              continue;
            string temp=h[i]+h[j];
            if(ispalin(temp))
            {
            cout<<temp<<endl;
              count++;
            }
            vis[i][j]=1;
            vis[j][i]=1;
        }
    }
    return count;
}
int main()
{
    vector<string> g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        g.push_back(temp);
    }
    cout<<find(g);
    return 0;
}
