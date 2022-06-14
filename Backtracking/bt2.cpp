/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10*/


//CODE:

    void permutate(vector<int> &ds,vector<int> &nums,vector<vector<int>> &res,int freq[])
    {
        if(ds.size()==nums.size())
        {
            res.push_back(ds);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(freq[i]==0)
            {
            ds.push_back(nums[i]);
            freq[i]=1;
            permutate(ds,nums,res,freq);
            freq[i]=0;
            ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res,finalres;
        set<vector<int>> st;
        vector<int> ds;
        int n=nums.size();
        int freq[n];
        vector<int> temp;
        for(int i=0;i<n;i++)
            freq[i]=0;
       permutate(ds,nums,res,freq);
        for(auto it:res)
            st.insert(it);
        for(auto it:st)
            finalres.push_back(it);
        return finalres;
    }
