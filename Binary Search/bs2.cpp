//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

//If target is not found in the array, return [-1, -1].

//You must write an algorithm with O(log n) runtime complexity.

//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]

//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]

//CODE:

 int firstocc(vector<int> &nums,int target)
    {
        int start=0;
        int res=-1;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
            {
                res=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return res;
    }
    int lastocc(vector<int> &nums,int target)
    {
        int start=0;
        int res=-1;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
            {
                res=mid;
                start=mid+1;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(firstocc(nums,target));
        res.push_back(lastocc(nums,target));
        return res;
    }
