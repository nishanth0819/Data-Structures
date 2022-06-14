/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"*/

//CODE:

 static bool comp(const string a,const string b)
    {
        return b+a<a+b;
    }
    string largestNumber(vector<int>& temp) {
        vector<string> nums;
        for(auto it:temp)
        {
            nums.push_back(to_string(it));
        }
        sort(nums.begin(),nums.end(),comp);
        string res="";
        for(auto it:nums)
            res=res+it;
        while(res[0]=='0' && res.size()>1)
            res.erase(0,1);
        return res;  
    }
