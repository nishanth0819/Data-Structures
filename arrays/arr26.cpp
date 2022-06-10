/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.*/


//CODE:

 int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int prev_max_sum=nums[0],prev_min_sum=nums[0],curr_max_sum=nums[0],curr_min_sum=nums[0];
        int minres=1e9,maxres=-1e9;
        for(int i=1;i<n;i++)
        {
            curr_max_sum=max(prev_max_sum+nums[i],nums[i]);
            curr_min_sum=min(prev_min_sum+nums[i],nums[i]);
            maxres=max(curr_max_sum,maxres);
            minres=min(curr_min_sum,minres);
            prev_max_sum=curr_max_sum;
            prev_min_sum=curr_min_sum;
        }
        if(sum==minres)
            return maxres;
        return max(maxres,sum-minres);
    }
