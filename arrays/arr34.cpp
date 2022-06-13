//Final Order should be with no adjacent duplicates while maintaining the order

/*I/P:122131
  O/P:31
  
  I/P: 122215523
  O/P:23
  
  I/P:1999115588
  O/P:NO BLOCK
*/

//CODE:

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string find(string g)
{
    stack<char> st;
    int n=g.size();
    int j=0;
    while(j<n)
    {
        int temp=j+1;
        if(st.empty()==true || st.top()!=g[j])
           st.push(g[j]);
        else
        {
            while(g[temp]==g[j] && temp<n)
                  temp++;
            st.pop();
        }
          j=temp;
    }
    if(st.empty()==true)
    {
        return "NO BLOCK";
    }
    string res="";
    while(st.empty()==false)
    {
        res=res+st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    string h1;
    cin>>h1;
    cout<<find(h1);
    return 0;
}

