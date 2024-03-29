/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.*/


//CODE:(Greedy)
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
            if(prices[i-1] < prices[i])
                profit += prices[i] - prices[i-1];
        return profit;
              
    }

//Recursive Code(TLE):
    int f(vector<int> &prices,int i,int n,int buy)
    {
        if(i==n)
            return 0;
        int profit=0;
        if(buy)
        {
            profit=max(-prices[i]+f(prices,i+1,n,0),f(prices,i+1,n,1));
        }
        else
            profit=max(prices[i]+f(prices,i+1,n,1),f(prices,i+1,n,0));
        return profit;
    }
    int maxProfit(vector<int>& prices) {
          int index=0,n=prices.size();
        int buy=1;
        return f(prices,index,n,buy);
    }

//Dynamic Programming (Bottom-Up)
int f(vector<int> &prices,int i,int n,int buy,vector<vector<int>> &dp)
    {
        if(i==n)
            return 0;
        int profit=0;
        if(dp[i][buy]!=-1e9)
            return dp[i][buy];
        if(buy)
        {
            profit=max(-prices[i]+f(prices,i+1,n,0,dp),f(prices,i+1,n,1,dp));
        }
        else
            profit=max(prices[i]+f(prices,i+1,n,1,dp),f(prices,i+1,n,0,dp));
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
          int index=0,n=prices.size();
        int buy=1;
        vector<vector<int>> dp(n+1,vector<int>(2,-1e9));
        return f(prices,index,n,buy,dp);
    }
