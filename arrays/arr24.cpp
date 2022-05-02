// Given a string S, find the length of the longest substring T that contains at most k distinct characters.
// Example
// Example 1:
// Input: S = "eceba" and k = 3
// Output: 4
// Explanation: T = "eceb"
// Example 2:
// Input: S = "WORLD" and k = 4
// Output: 4
// Explanation: T = "WORL" or "ORLD"
// Challenge
// O(n) time

//CODE:
int getLengthofLongestSubstring(int k, string s)
{
   map<char,int> mp;
	int i=0,j=0,n=s.length();
	int maxl=-1e9;
	while(j<n)
	{
		mp[s[j]]++;
		while(mp.size()>k)
		{
			mp[s[i]]--;
			if(mp[s[i]]==0)
				mp.erase(s[i]);
			i++;
		}
		j++;
		maxl=max(maxl,j-i);
	}
	return maxl;
}
