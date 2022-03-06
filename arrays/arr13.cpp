/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.*/

//CODE:

string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:t)
            mp[it]++;
        int  i=0,j=0,n=s.size(),minstart=0,minlength=1e9;
         int  count=t.size();
        while(j<n)
        {
            if(mp[s[j]]>0)
                count--;
            mp[s[j]]--;
            j++;
            while(count==0)
            {
                if(j-i<minlength)
                {
                    minstart=i;
                    minlength=j-i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    count++;
                i++;
            }
        }
          if(minlength!=1e9)
            return s.substr(minstart,minlength);
        return "";
        
    }
