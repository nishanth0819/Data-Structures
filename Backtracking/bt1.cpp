/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.*/


//CODE:
 void permutate(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[])
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                permutate(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=nums.size();
        int freq[n];
        for(int i=0;i<n;i++)
            freq[i]=0;
        permutate(ds,nums,ans,freq);
        return ans;
    }
