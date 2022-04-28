//https://leetcode.com/problems/contains-duplicate-ii/

/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

//CODE -BruteForce

 bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n && j<=i+k;j++)
            {
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;
        

    }
//OPTIMIZED CODE:

  bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++)
        {
            if(i>k)
                st.erase(nums[i-k-1]);
            if(st.find(nums[i])!=st.end())
                return true;
            st.insert(nums[i]);
        }
        return false;
        
    }
