/*You will be given three strings, find the second string in first string and replace it with third string */

//CODE:

#include <iostream>
using namespace std;
int find(string a,string b)
{
    int n1=a.size();
    int n2=b.size();
    int j=0;
    while(j<n1-n2+1)
    {
        int temp=j;
        int count=0;
        for(int i=0;i<n2;i++)
        {
            if(a[temp]!=b[i])
            {
                break;
            }
            count++;
            temp++;
        }
        if(count==n2)
        {
          break;
        }
        j++;
    }
    return j;
}
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    int index=find(a,b);
    string res="";
    for(int i=0;i<index;i++)
    {
        res=res+a[i];
    }
    int a1=c.size();
    for(int i=0;i<a1;i++)
    {
        res=res+c[i];
    }
    int b1=index+b.size();
    for(int i=b1;i<a.size();i++)
    {
        res=res+a[i];
    }
    cout<<res;
    return 0;
}
