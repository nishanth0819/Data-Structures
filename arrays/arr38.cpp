/*You are given 2 arrays A and B of size N and an integer k .you need to select k indices (0<=i1,i2,i3...ik<N) let X=max(A[i1],A[i2],A[i3]..A[ik]),Y=B[i1]+B[I2]+..B[IK]
find the minimum value of X^2Y*/

//CODE:
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int res=1e9;
void generate(int index,vector<int> arr1,vector<int> arr2,vector<int> res1,vector<int> res2,int n,int k)
{
    if(index==n)
    {
        int maxi=-1e9;
        if(res1.size()==k)
        {
            for(auto it:res1)
            {
                maxi=max(it,maxi);
            }
            int sum=0;
            for(auto it:res2)
            {
                sum=sum+it;
            }
            res=min(res,(maxi*maxi)*sum);
        }
        return ;
        
    }
    res1.push_back(arr1[index]);
    res2.push_back(arr2[index]);
    generate(index+1,arr1,arr2,res1,res2,n,k);
    res1.pop_back();
    res2.pop_back();
    generate(index+1,arr1,arr2,res1,res2,n,k);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a,b;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    vector<int> res1,res2;
    generate(0,a,b,res1,res2,n,k);
    cout<<res;
}
