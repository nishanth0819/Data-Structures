//Given a sequence, find the length of the longest palindromic subsequence in it.

//I/P:abac
//O/P:3

//I/P:govardhan
//O/P:3



//CODE:
int find(string g,int i,int j)
{
    if(i==j)
        return 1;
    if(g[i-1]==g[j-1] && i+1==j)
        return 2;
    else if(g[i-1]==g[j-1])
        return 2+find(g,i+1,j-1);
    else
        return max(find(g,i+1,j),find(g,i,j-1));
}
string longestPalinSubstring(string str)
{
    return find(str,0,str.size());
}
