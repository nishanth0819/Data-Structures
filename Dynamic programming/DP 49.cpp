// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:

// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0

//CODE:

    int maximalSquare(vector<vector<char>>& matrix)  {
        int rows=matrix.size();
        int col=matrix[0].size();
        if(rows==0)
            return 0;
        vector<vector<int>> dp(rows+1,vector<int>(col+1,0));
        int largest=0;
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    if(dp[i][j]>largest)
                        largest=dp[i][j];
                }
            }
        }
        return largest*largest;
    }
