// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is rotated at an unknown pivot index 
// k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1],
//                                                            ..., nums[n-1], 
//                                                            nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
//   For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, return the index of target
// if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104


//CODE:

  int find(int start,int end,int target,vector<int> arr)
    {
        while(start<=end)
        {
            int mid=start+(end - start)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int findminindex(vector<int> nums)
    {
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        while(low<=high)
        {
            int mid=(low+high)/2;
            int prev=(mid-1+n)%n,next=(mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return mid;
            else if(nums[mid]<=nums[high])
                high=mid-1;
            else if(nums[mid]>=nums[low])
                low=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=findminindex(nums);
        int res1=find(0,index-1,target,nums);
        int res2=find(index,nums.size()-1,target,nums);
        if(res1!=-1)
            return res1;
        else if(res2!=-1)
            return res2;
        else    
        return -1;
    }
