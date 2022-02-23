//Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
//Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
//Output: 106
//Explanation:The maximum sum of a
//increasing sequence is obtained from
//{1, 2, 3, 100}

//Input: N = 3, arr[] = {1, 2, 3}
//Output: 6
//Explanation:The maximum sum of a
//increasing sequence is obtained from
//{1, 2, 3}

//Method1:
int find(int i,vector<int> nums,int prev)
    {
        if(i==0)
            return 0;
        int ex=find(i-1,nums,prev);
        int in=0;
        if(nums[i-1]<prev)
            in=nums[i-1]+find(i-1,nums,nums[i-1]);
        return max(in,ex);
    }	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> nums;
	    for(int i=0;i<n;i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    return find(n,nums,1e9);
	}

//Method2:

map<pair<int,int>,int> mp;
	int find(int i,vector<int> nums,int prev)
    {
        if(i==0)
            return 0;
        auto it=mp.find({i,prev});
          if(it!=mp.end())
               return mp[{i,prev}];
        int ex=find(i-1,nums,prev);
        int in=0;
        if(nums[i-1]<prev)
            in=nums[i-1]+find(i-1,nums,nums[i-1]);
        return mp[{i,prev}]=max(in,ex);
    }	

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> nums;
	    for(int i=0;i<n;i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    return find(n,nums,1e9);
	}

//method3:

int find(int prev,int curr,vector<int> nums)
	{
	    if(curr==nums.size())
	        return 0;
	    int op1=0;
	    if(prev==-1 || nums[prev]<nums[curr])
	    {
	           op1=nums[curr]+find(curr,curr+1,nums);
	    }
	    int op2=find(prev,curr+1,nums);
	    return max(op1,op2);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> nums;
	    for(int i=0;i<n;i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    return find(-1,0,nums);
	}

//method4:
vector<vector<int>> dp;
	int find(int prev,int curr,vector<int> nums)
	{
	    if(curr==nums.size())
	        return 0;
	    int op1=0;
	    if(prev!=-1 && dp[prev][curr]!=-1)
	         return dp[prev][curr];
	    if(prev==-1 || nums[prev]<nums[curr])
	    {
	           op1=nums[curr]+find(curr,curr+1,nums);
	    }
	    int op2=find(prev,curr+1,nums);
	    if(prev!=-1)
	       dp[prev][curr]=max(op1,op2);
	    return max(op1,op2);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> nums;
	    for(int i=0;i<n;i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    dp.clear();
	    dp.resize(n+1,vector<int>(n+1,-1));
	    return find(-1,0,nums);
	}
