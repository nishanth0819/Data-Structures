/*Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.


Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.*/


//CODE:

int longestKSubstr(string s, int k) {
         int maxi=-1;
         int i=0,j=0;
         int n=s.length();
         unordered_map<int,int> mp;
         while(j<n)
         {
             mp[s[j]]++;
             if(mp.size()<k)
                 j++;
             else if(mp.size()==k)
             {
                 maxi=max(maxi,j-i+1);
                 j++;
             }
             else if(mp.size()>k)
             {
                 while(mp.size()>k)
                 {
                     mp[s[i]]--;
                     if(mp[s[i]]==0)
                       mp.erase(s[i]);
                     i++;
                 }
                 j++;
             }
         }
         return maxi;
    }
