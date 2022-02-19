//You are given ‘N’ integers in the form of an array ‘ARR’. Count the number of subarrays having their sum as 0.
//I/P:
//3
//1 4 -5
//O/P:1
//The subarray [1, 4, -5] has a sum equal to 0. 
//So the count is 1.
//I/P:
//4
//-1 1 0 1
//O/P:
//3
//The subarray [-1, 1], [-1, 1, 0] and  [0] has a sum equal to 0. 
//So the count is 3.
//CODE:

int countSubarrays(int n, vector<int> &arr){
    unordered_map<int,int> mp;
    mp.insert({0,1});
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(mp.find(sum)==mp.end())
            mp[sum]=1;
        else
        {
            count=count+mp[sum];
            mp[sum]++;
        }
    }
    return count;
}
