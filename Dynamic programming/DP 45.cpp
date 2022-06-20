/*You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 
 

Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

â€‹Example 2:

Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.
 

Your Task:
You don't need to read input or print anything. Your task is to Complete the function maxChainLen() which takes a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.

 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)*/


//CODE:
bool iscompare(int a,int b)
{
    return a>b;
}
int findg(struct val p[],int i,struct val *prev,int n)
{
    if(i>=n)
       return 0;
    int in=0;
    if(prev==NULL || iscompare(p[i].first,prev->second))
    {
        struct val *temp=new val;
        temp->first=p[i].first;
        temp->second=p[i].second;
          in=1+findg(p,i+1,temp,n);
    }
    int ex=findg(p,i+1,prev,n);
    return max(in,ex);
       
}
    bool comp(struct val &s1,struct val&s2)
    {
        return s1.first<s2.first;
    }
int maxChainLen(struct val p[],int n)
{
     struct val *prev=NULL;
     sort(p,p+n,comp);
     int i=0;
     return findg(p,i,prev,n);
}
