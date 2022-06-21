/*Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example 1:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 
Example 2:

Input: N = 5, arr[] = {-1, -1, 4, 3, -1}
W = 5
Output: -1
Explanation: It is not possible to buy 5 
kgs of oranges

Your Task:  
You don't need to read input or print anything. Complete the function minimumCost() which takes N, W, and array cost as input parameters and returns the minimum value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(N*W)*/

//CODE:(TLE)

	int find(int cost[],int n,int w)
	{
	    if(w==0)
	       return 0;
	   if(n==0 || w<0)
	      return 1e9;
	    if(cost[n-1]!=-1)
	      return min(cost[n-1]+find(cost,n,w-n),find(cost,n-1,w));
	   else
	      return find(cost,n-1,w);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        
        int res=find(cost,N,W);
        if(res==0)
           return -1;
        return res;
	}

//MEMORIZATION:

int find(int cost[],int n,int w,vector<vector<int>> &dp)
	{
	    if(w==0)
	       return 0;
	   if(n==0 || w<0)
	      return 1e9;
	   if(dp[n][w]!=-1)
	       return dp[n][w];
	    if(cost[n-1]!=-1)
	      return dp[n][w]=min(cost[n-1]+find(cost,n,w-n,dp),find(cost,n-1,w,dp));
	   else
	      return dp[n][w]=find(cost,n-1,w,dp);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>> dp(201,vector<int>(200,-1));
        int res=find(cost,N,W,dp);
        if(res==0)
           return -1;
        return res;
	} 
