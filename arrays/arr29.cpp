/*Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
*/

//CODE:

    bool increasingTriplet(vector<int>& nums) {
        long firstmini=INT_MAX;
        long secondmini=INT_MAX;
        for(auto it:nums)
        {
            if(it<=firstmini)
                firstmini=it;
            else if(it<=secondmini)
                secondmini=it;
            else if(it>secondmini)
                return true;
        }
        return false;
        
    }
