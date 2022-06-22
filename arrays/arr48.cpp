/*Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104*/

//CODE:(TLE)
 int find(vector<int> &nums,int target,int i,int j)
    {
        int flag=0;
        int sum=0;
        for(int k=i;k<=j;k++)
        {
            sum=sum+nums[k];
        }
        if(sum>=target)
            return j-i+1;
        return 1e9;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
          int minlen=1e9;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int x=find(nums,target,i,j);
                minlen=min(minlen,x);
            }
        }
        if(minlen==1e9)
            return 0;
        return minlen;
    }

//Optimized Code:

 int minSubArrayLen(int target, vector<int>& nums) {
          int minlen=1e9;
        int n=nums.size();
        int j=0,i=0;
        int sum=0;
        while(j<n)
        {
            sum=sum+nums[j];
            if(sum<target)
            {
                j++;
            }
            else if(sum>=target)
            {
                while(sum>=target)
                {
                    minlen=min(minlen,j-i+1);
                    sum=sum-nums[i];
                    i++;
                }
                j++;
            }
        }
        return (minlen==1e9)?0:minlen;
        
    }
