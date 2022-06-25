/*You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104*/

//Recursive Code(TLE):
    int find(vector<int> &prices,int i,int n,int buy,int fee)
    {
        if(i==n)
            return 0;
        int profit=0;
        if(buy)
            profit=max(-prices[i]+find(prices,i+1,n,0,fee),find(prices,i+1,n,1,fee));
        else
            profit=max(prices[i]-fee+find(prices,i+1,n,1,fee),find(prices,i+1,n,0,fee));
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int i=0,buy=1;
        return find(prices,i,n,buy,fee);
    }
//Bottom-Up Code(DP)
 int find(vector<int> &prices,int i,int n,int buy,int fee)
    {
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1e9)
            return dp[i][buy];
        int profit=0;
        if(buy)
            profit=max(-prices[i]+find(prices,i+1,n,0,fee),find(prices,i+1,n,1,fee));
        else
            profit=max(prices[i]-fee+find(prices,i+1,n,1,fee),find(prices,i+1,n,0,fee));
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int i=0,buy=1;
        dp.resize(n+1,vector<int>(2,-1e9));
        return find(prices,i,n,buy,fee);
    }
