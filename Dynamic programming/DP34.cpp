// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.
// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4


//RECURSICE CODE:
int find(string a,string b,int m,int n)
    {
        if(m==0||n==0)
            return 0;
        if(a[m-1]==b[n-1])
            return 1+find(a,b,m-1,n-1);
        else
            return max(find(a,b,m-1,n),find(a,b,m,n-1));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        return m+n-(2*find(word1,word2,m,n));
        
    }
//BOTTOM-UP CODE:
 vector<vector<int>> dp;
    int find(string a,string b,int m,int n)
    {
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(m==0||n==0)
            return 0;
        if(a[m-1]==b[n-1])
            return dp[m][n]=1+find(a,b,m-1,n-1);
        else
            return dp[m][n]=max(find(a,b,m-1,n),find(a,b,m,n-1));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        dp.clear();
        dp.resize(m+1,vector<int>(n+1,-1));
        return m+n-(2*find(word1,word2,m,n));
        
    }
//TOP-DOWN CODE:

int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
            vector<vector<int>> dp;

        dp.clear();
        dp.resize(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (m+n)-(2*dp[m][n]);
        
    }
