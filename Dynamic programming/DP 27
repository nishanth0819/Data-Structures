//Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

//Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6

//Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3


//RECURSIVE CODE:

int find(int i,vector<int> nums,int prev)
    {
        if(i==0)
            return 0;
        int ex=find(i-1,nums,prev);
        int in=0;
        if(nums[i-1]<prev)
            in=1+find(i-1,nums,nums[i-1]);
        return max(in,ex);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=1e9;
        return find(n,nums,prev);
    }
    
    
    
 //Bottom-up Code:
 
 int find(int i,vector<int> nums,int prev,map<pair<int,int>,int> &mp)
    {
        if(i==0)
            return 0;
        auto it=mp.find({i,prev});
        if(it!=mp.end())
            return mp[{i,prev}];
        int ex=find(i-1,nums,prev,mp);
        int in=0;
        if(nums[i-1]<prev)
            in=1+find(i-1,nums,nums[i-1],mp);
        return mp[{i,prev}]=max(in,ex);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=1e9;
        map<pair<int,int>,int> mp;
        return find(n,nums,prev,mp);
    }
    
    
 //TOP-DOWN CODE:
 
 
 nt lengthOfLIS(vector<int>& a) {
        vector<int> l(a.size(),0);
        l[0]=1;
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i] && l[j]>l[i])
                    l[i]=l[j] ;           
            }
            l[i]++;
        }
        int maxi=-1e9;
        for(auto it:l)
        {
            if(maxi<it)
                maxi=it;
        }
        return maxi;
    }
