/*You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.*/


//CODE:

    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> mp;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum=sum+nums[i];
        if(x>sum)
            return -1;
       int target=sum-x;
        if(target == 0) return n;
        int longest=-1e9;
        int prefix=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            prefix=prefix+nums[i];
            if(mp.find(prefix-target)!=mp.end())
                longest=max(longest,i-mp[prefix-target]);
            mp[prefix]=i;
        }
        if(longest==-1e9)
            return -1;
        return n-longest;
    }
