//Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. 
//Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
//Note: Return -1 if you can't reach the end of the array.

//Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
  
//Input :
N = 6
arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.
  
  
//CODE:
unordered_map<long long,long long> dp;
   
   int findans(int arr[],int n,int i)
   {
       if(i==n-1)
           return 0; 
           
       if(i>=n)
           return -1;
           
       if(arr[i]==0)
       	   return -1;
       	   
       if(dp.find(i)!=dp.end())
           return dp[i];
           
        long long ans=INT_MAX;
       for(int j=1;j<=arr[i];j++)
       {
           long long temp=findans(arr,n,i+j);
           if(temp>-1)
               ans=min(ans,temp+1);
       }
       
       if(ans==INT_MAX)
           ans=-1;
       
       dp[i]=ans;
       return ans;
   }
 
   int minJumps(int arr[], int n){
       dp.clear(); 
       return findans(arr,n,0);
   }
