/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.*/

//CODE(TLE):
    int findMaxLength(vector<int>& nums) {
        int i=0,n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int zeros=0,ones=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==0)
                    zeros++;
                else
                    ones++;
                if(zeros==ones)
                    maxi=max(maxi,j-i+1);
                    
            }
        }
        return maxi;
    }

//OPTIMIZED CODE:

 int findMaxLength(vector<int>& nums) {
        int i=0,n=nums.size();
        int maxi=0;
        int sum=0;
        map<int,int> mp;
        mp.insert({0,-1});
        for(int i=0;i<n;i++)
        {
            sum=sum+(nums[i]==0?-1:1);
            if(mp.find(sum)!=mp.end())
            {
                int len=i-mp[sum];
                maxi=max(len,maxi);
            }
            else
                mp.insert({sum,i});
        }
        return maxi;
    }
