/*Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.
Examples: 

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.

Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}       
Output : 110 
We get maximum value with one unit of
weight 5 and one unit of weight 3.*/
CODE:
BOTTOM-UP APPROACH
#include <iostream>

using namespace std;
int knapsack(int wt[],int val[],int W,int n,int dp[][100])
{
    if(n==0||W==0)
    {
        return 0;
    }
   
    if(wt[n-1]<=W)
    {
        return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n,dp),knapsack(wt,val,W,n-1,dp));
    }
    else
    return dp[n][W]=knapsack(wt,val,W,n-1,dp);
}

int main() {
    int weights[100];
    int values[100];
    int W,n,dp[100][100];
    cin>>n>>W;
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>values[j];
    } 
    
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        dp[i][j]=0;
    }
}
   cout<<knapsack(weights,values,W,n,dp);
}
//TOP-DOWN
int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(N+1,vector<int>(W+1));
        
        for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0|| j==0)
            {
                dp[i][j]=0;
            }
           else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
       return dp[N][W]; 
    }
