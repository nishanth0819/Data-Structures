/*Problem Statement
You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note:
Strings don't contain spaces in between.
 Input Format:
The first line of input contains the string 'S' of length 'N'.

The second line of the input contains the String 'T' of length 'M'.
Output Format:
The only line of output prints the minimum "Edit Distance" between the strings.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given functions.
Constraints:
0 <= N <= 10 ^ 3
0 <= M <= 10 ^ 3

Time Limit : 1sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation For Sample Input 1 :
In 2 operations we can make the string T to look like string S. First, insert the character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of the string T with 'b' from the string S. This would make string T to "abc" which is also the string S. Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9*/


//RECURSIVE CODE:

string s1,s2;
int find(int i,int j)
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(s1[i-1]==s2[j-1])
        return find(i-1,j-1);
    else
    {
        int a=1+find(i-1,j);
        int b=1+find(i,j-1);
        int c=1+find(i-1,j-1);
        return min(a,min(b,c));
    }
}
int editDistance(string str1, string str2)
{
    s1=str1;
    s2=str2;
    return find(s1.length(),s2.length());
}

//BOTTOM-UP CODE:
string s1,s2;
vector<vector<int>> dp;
int find(int i,int j)
{
    if(i==0)
        return dp[i][j]=j;
    if(j==0)
        return dp[i][j]=i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i-1]==s2[j-1])
        return dp[i][j]=find(i-1,j-1);
    else
    {
        int a=1+find(i-1,j);
        int b=1+find(i,j-1);
        int c=1+find(i-1,j-1);
        return dp[i][j]=min(a,min(b,c));
    }
}
int editDistance(string str1, string str2)
{
    s1=str1;
    s2=str2;
    dp.clear();
    dp.resize(str1.size()+1,vector<int>(str2.size()+1,-1));
    return find(s1.length(),s2.length());
}
