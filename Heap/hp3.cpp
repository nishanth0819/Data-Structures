/*Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.*/

//CODE:

 string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(int i=0;s[i]!='\0';i++)
        {
            mp[s[i]]++;
        }
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string res;
        while(pq.size()>1)
        {
            
            auto curr=pq.top();
            pq.pop();
            auto next=pq.top();
            pq.pop();
            res=res+curr.second;
            res=res+next.second;
            curr.first=curr.first-1;
            next.first=next.first-1;
            if(curr.first>0)
                pq.push({curr.first,curr.second});
            if(next.first>0)
                pq.push({next.first,next.second});
        }
        if(pq.size()==1)
        {
            auto temp=pq.top();
            if(temp.first>1)
                return "";
            res=res+temp.second;
        }
        return res;
    }
