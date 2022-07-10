#include <iostream>
#include<bits/stdc++.h>
using namespace std;
list<int> dq;
map<int,list<int>::iterator> mp;
int csize;
void refer(int n)
{
    if(mp.find(n)==mp.end())
    {
        if(dq.size()==csize)
        {
            int last=dq.back();
            dq.pop_back();
            mp.erase(last);
        }
    }
    else
         dq.erase(mp[n]);
    dq.push_front(n);
    mp[n]=dq.begin();
}
void display()
{
    for(auto it:dq)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    csize=4;
     refer(1);
    refer(2);
    refer(3);
    refer(1);
    refer(4);
    refer(5);
    display();

    return 0;
}
