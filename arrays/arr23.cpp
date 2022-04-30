// Given a string s and an integer k, return the length of the longest substring
// of s such that the frequency of each character in this substring is greater
// than or equal to k.

// Example 1:
// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:
// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 
// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105

//CODE:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map<int,int> mp;
            for(int j=i;j<n;j++)
            {
                int flag=1;
                mp[s[j]]++;
                for(auto it:mp)
                {
                    if(it.second<k)
                        flag=0;
                }
                if(flag==1)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
        
    }
