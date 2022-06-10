 // Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// It is guaranteed that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#CODE:

 int maxProduct(vector<int>& nums) {
        int n=nums.size();
       int ma=nums[0],mi=nums[0],ans=nums[0];
        if(n==0) 
            return 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
                swap(ma,mi);
            ma=max(nums[i],ma*nums[i]);
            mi=min(nums[i],mi*nums[i]);
            ans=max(ma,ans);
        }
        return ans;
        
    }

//Alternate Method


 int maxProduct(vector<int>& nums) {
       int curr_max_pro=nums[0],prev_max_pro=nums[0],res=nums[0],prev_min_pro=nums[0];
        int curr_min_pro=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            curr_max_pro=max({prev_max_pro*nums[i],prev_min_pro*nums[i],nums[i]});
            curr_min_pro=min({prev_max_pro*nums[i],prev_min_pro*nums[i],nums[i]});
            res=max(res,curr_max_pro);
            prev_max_pro=curr_max_pro;
            prev_min_pro=curr_min_pro;
        }
        return res;
    }
