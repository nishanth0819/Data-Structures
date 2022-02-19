//Given an array arr of length N consisting of positive and negative integers, return the length of the longest subarray whose sum is zero.
//INPUT:
5
3 -2 1 -2 1
OUTPUT:
4
There are two subarrays whose sum is zero arr[0...3], arr[2...4] i.e {3, -2, 1, -2}, and {1, -2, 1}
The longest subarray of these is of length 4.
  
//INPUT:
4
1 -1 2 -2
OUTPUT:2
  
CODE:
int lengthOfLongestSubarray(int arr[],int n)
{
    int maxl=0;
    unordered_map<int,int> mp;
    mp.insert({0,-1});
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
        else
        {
            int len=i-mp[sum];
            maxl=max(maxl,len);
        }
    }
    return maxl;
}
