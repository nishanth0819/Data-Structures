//SORT THE STRINGS
/*I/P:
3
12
77777778899
111111
O/P:
12
111111
77777778899*/

//CODE:
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(const string &a,const string &b)
{
    if(a.size()!=b.size())
       return a.size()<b.size();
    return a<b;
}
int main()
{
    vector<string> res;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        res.push_back(temp);
    }
    sort(res.begin(),res.end(),comp);
    for(auto it:res)
    {
        cout<<it<<endl;
    }
    return 0;
}


