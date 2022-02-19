//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k
//Input: nums = [1,1,1], k = 2
//Output: 2
//Input: nums = [1,2,3], k = 3
//Output: 2


//CODE:

int subarraySum(vector<int>& nums, int k) {
        int count=0;
        map<int,int> mp;
        mp.insert({0,1});
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(mp.find(sum-k)!=mp.end())
                count=count+mp[sum-k];
            mp[sum]++;
            
        }
        return count;
        
    }
