/*Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

Example 1:


Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7 */

//CODE:(TLE)
    int find(vector<vector<int>> &grid,int i,int j,int n)
    {
        if(i==n-1)
            return grid[i][j];
        int tempans=1e9;
        for(int k=0;k<n;k++)
        {
            if(k!=j)
            {
                int cost=grid[i][j]+find(grid,i+1,k,n);
                tempans=min(tempans,cost);
            }
                
        }
        return tempans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int mini=1e9;
        for(int i=0;i<cols;i++)
        {
            int temp=find(grid,0,i,rows);
            if(temp<mini)
                mini=temp;
        }
        return mini;
    }

//DP-CODE(TOP-DOWN)
 vector<vector<int>> dp;
    int find(vector<vector<int>> &grid,int i,int j,int n)
    {
        if(i==n-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int tempans=1e9;
        for(int k=0;k<n;k++)
        {
            if(k!=j)
            {
                int cost=grid[i][j]+find(grid,i+1,k,n);
                tempans=min(tempans,cost);
            }
                
        }
        return dp[i][j]=tempans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int mini=1e9;
        dp.resize(rows+1,vector<int>(cols+1,-1));
        for(int i=0;i<cols;i++)
        {
            int temp=find(grid,0,i,rows);
            if(temp<mini)
                mini=temp;
        }
        return mini;
    }
