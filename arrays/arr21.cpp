/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.*/


//CODE:

    vector<int> findAnagrams(string s, string p) {
        map<int,int> mp1,mp2;
        for(auto it:p)
            mp2[it]++;
        int k=p.size();
        int j=0,n=s.size(),i=0;
        vector<int> res;
        while(j<n)
        {
            mp1[s[j]]++;
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if(mp1==mp2)
                    res.push_back(i);
                mp1[s[i]]--;
                if(mp1[s[i]]==0)
                    mp1.erase(s[i]);
                i++;
                j++;
            }
        }
        return res;
        
        
    }
