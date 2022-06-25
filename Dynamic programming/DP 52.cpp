/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105*/

//CODE(TLE):
int find(vector<int> &prices,int i,int n,int buy,int k)
    {
        if(i==n || k==0)
            return 0;
        int profit=0;
        if(buy)
            profit=max(-prices[i]+find(prices,i+1,n,0,k),find(prices,i+1,n,1,k));
        else
            profit=max(prices[i]+find(prices,i+1,n,1,k-1),find(prices,i+1,n,0,k));
        return profit;
            
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,buy=1;
        int k=2;
        return find(prices,i,n,buy,k);
    }


//DP(Bottom-Up)

  vector<vector<vector<int>>> dp;
    int find(vector<int> &prices,int i,int n,int buy,int k)
    {
        if(i==n || k==0)
            return 0;
        if(dp[i][buy][k]!=-1e9)
            return dp[i][buy][k];
        int profit=0;
        if(buy)
            profit=max(-prices[i]+find(prices,i+1,n,0,k),find(prices,i+1,n,1,k));
        else
            profit=max(prices[i]+find(prices,i+1,n,1,k-1),find(prices,i+1,n,0,k));
        return dp[i][buy][k]=profit;
            
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,buy=1;
        int k=2;
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,-1e9)));
        return find(prices,i,n,buy,k);
    }
