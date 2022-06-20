/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]*/


//CODE:

vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int target=n/3;
        vector<int> res;
        for(auto it:mp)
        {
            if(it.second>target)
                res.push_back(it.first);
        }
        return res;
        
    }
