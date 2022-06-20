/*You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.*/


//CODE:

 bool check(string g)
    {
        set<char> st;
        for(auto it:g)
        {
            if(st.find(it)!=st.end())
                return false;
            st.insert(it);
        }
        return true;
    }
    bool cantake(string a,string b)
    {
        map<char,int> mp;
        for(auto it:a)
            mp[it]++;
        for(auto it:b)
        {
            if(mp.find(it)!=mp.end())
                return false;
        }
        return true;
    }
    int find(vector<string> &arr,int n,string res)
    {
        if(n==0)
            return 0;
        int take=0;
        if((res==""|| cantake(arr[n-1],res)) && check(arr[n-1]))
        {
            string temp=res+arr[n-1];
            take=arr[n-1].size()+find(arr,n-1,temp);
        }
        int nottake=find(arr,n-1,res);
        return max(take,nottake);   
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string res="";
        return find(arr,n,res);
    }
