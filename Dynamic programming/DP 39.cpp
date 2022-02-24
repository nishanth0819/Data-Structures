//https://www.codingninjas.com/codestudio/problems/maximum-sum-subsequence_1230547?leftPanelTab=0

//You are given an array “NUMS” consisting of N integers and an integer, K. Your task is to determine the maximum sum of an increasing subsequence of length K.
//I/P:
//1
//5 3
//1 3 -2 4 5
//o/p:12


//CODE:

int find(int prev,int curr,vector<int> nums,vector<int> &ans,int k)
{
    if(ans.size()==k)
    {
        int val=0;
        for(auto it:ans)
        {
            if(it<0)
                return 0;
            val=val+it;
        }
        return val;
    }
    if(curr==nums.size())
        return 0;
    int op1=0;
    ans.push_back(nums[curr]);
    if(prev==-1||nums[prev]<=nums[curr])
    {
        
        op1=find(curr,curr+1,nums,ans,k);
    }
    ans.pop_back();
    int op2=find(prev,curr+1,nums,ans,k);
    return max(op1,op2);
}
long long maximumSum(vector<int>& nums, int k) {
    vector<int> ans;
	int res=find(-1,0,nums,ans,k);
    
    if(res==0)
        return -1;
    else
        return res;
}
