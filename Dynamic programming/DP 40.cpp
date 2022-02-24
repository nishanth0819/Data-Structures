// Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

// Recall that a subsequence of an array nums is a list nums[i1], nums[i2], ..., nums[ik] with 0 <= i1 < i2 < ... < ik <= nums.length - 1, and that a sequence seq is arithmetic if seq[i+1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

 

// Example 1:

// Input: nums = [3,6,9,12]
// Output: 4
// Explanation: 
// The whole array is an arithmetic sequence with steps of length = 3.
// Example 2:

// Input: nums = [9,4,7,2,10]
// Output: 3
// Explanation: 
// The longest arithmetic subsequence is [4,7,10].
// Example 3:

// Input: nums = [20,1,15,3,10,5,8]
// Output: 4
// Explanation: 
// The longest arithmetic subsequence is [20,15,10,5].
 

// Constraints:

// 2 <= nums.length <= 1000
// 0 <= nums[i] <= 500


//RECUSICE CODE:

 int findin(int prev,int curr,vector<int> &nums,vector<int> &ans)
    {
        if(curr==nums.size())
        {
            int n=ans.size();
            if(n==1 || n==2)
                return n;
            int diff=ans[1]-ans[0];
            for(int i=0;i<n-1;i++)
            {
                if(ans[i+1]-ans[i]!=diff)
                    return 0;
            }
            return ans.size();
        }
        
        int op1=0;
        ans.push_back(nums[curr]);
        if(prev==-1 || nums[prev]<nums[curr])
            op1=findin(curr,curr+1,nums,ans);
        ans.pop_back();
        int op2=findin(prev,curr+1,nums,ans);
        return max(op1,op2);
    }
    int findde(int prev,int curr,vector<int> &nums,vector<int> &ans1)
    {
        
        if(curr==nums.size())
        {
            int n=ans1.size();
            if(n==1 || n==2)
                return n;
            int diff=ans1[0]-ans1[1];
            for(int i=0;i<n-1;i++)
            {
                if(ans1[i]-ans1[i+1]!=diff)
                    return 0;
            }
            return ans1.size();
        }
        int op1=0;
        ans1.push_back(nums[curr]);
        if(prev==-1 || nums[prev]>nums[curr])
            op1=findde(curr,curr+1,nums,ans1);
        ans1.pop_back();
        int op2=findde(prev,curr+1,nums,ans1);
        return max(op1,op2);
    }
    int longestArithSeqLength(vector<int>& nums) {
        vector<int> ans1,ans2;
        int g1=findin(-1,0,nums,ans1);
        int g2=findde(-1,0,nums,ans2);
        return max(g1,g2);
    }
