/*Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa" 
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)

*/

//RECURSIVE CODE:

bool check(string s,int i,int j)
   {
       while(i<j)
       {
           if(s[i]!=s[j])
               return false;
            i++;
            j--;
       }
       return true;
   }
    int find(string s,int i,int j)
    {
        if(i>j || check(s,i,j))
           return 0;
        int ans=1e9;
        for(int k=i;k<j;k++)
        {
            int res=find(s,i,k)+find(s,k+1,j)+1;
            if(res<ans)
               ans=res;
        }
        return ans;
    }
    int palindromicPartition(string str)
    {
        return find(str,0,str.length()-1);
    }

//BOTTOM-UP CODE:

//vector<vector<int>> dp;
   int dp[501][501];
   bool check(string &s,int i,int j)
   {
       while(i<j)
       {
           if(s[i]!=s[j])
               return false;
            i++;
            j--;
       }
       return true;
   }
    int find(string &s,int i,int j)
    {
        if(i>j || check(s,i,j))
           return dp[i][j]=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1e9;
        for(int k=i;k<j;k++)
        {
            int res=find(s,i,k)+find(s,k+1,j)+1;
            if(res<ans)
               ans=res;
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        int n=str.length();
       // dp.clear();
       // dp.resize(n+1,vector<int>(n+1,-1));
       memset(dp,-1,sizeof(dp));
        return find(str,0,str.length()-1);
    }
