//You are given an array “nums” of size N.
// Your task is to find the length of the longest subsequence of array “nums” such that the absolute difference between every adjacent element in the subsequence is one.
//I/P:
//If “nums” = {2, 1, 3}.
//The valid non-empty subsequences of the array are {2}, {1}, {3}, {2, 1}, {1, 3}, {2, 3} and {2, 1, 3}. 
//So, the longest subsequence satisfying the given conditions are {2, 1} and {2, 3}. The length of the longest subsequence is 2. So, the answer is 2.

//I/P:
//5
//4 2 1 5 6
//O/P:3
//I/P:
//5 6 5 6
//O/P:1

//RECURSIVE CODE:

int find(int prev,int i,vector<int> &nums)
{
    if(i==nums.size())
        return 0;
    int op1=0;
    if(prev==-1 ||nums[i]-nums[prev]==1||nums[prev]-nums[i]==1)
        return 1+find(i,i+1,nums);
    int op2=find(prev,i+1,nums);
    return max(op1,op2);
}
int longestSubsequence(vector<int> &nums){
    return find(-1,0,nums);
}

//MEMORIZATION:
int find(int prev,int i,vector<int> &nums,map<pair<int,int>,int> &mp)
{
    if(i==nums.size())
        return 0;
    auto it=mp.find({i,prev});
    if(it!=mp.end())
        return mp[{i,prev}];
    int op1=0;
    if(prev==-1 ||nums[i]-nums[prev]==1 || nums[prev]-nums[i]==1)
        op1=1+find(i,i+1,nums,mp);
    int op2=find(prev,i+1,nums,mp);
    return mp[{i,prev}]=max(op1,op2);
}
int longestSubsequence(vector<int> &nums){
    map<pair<int,int>,int> mp;
    return find(-1,0,nums,mp);
}

 
