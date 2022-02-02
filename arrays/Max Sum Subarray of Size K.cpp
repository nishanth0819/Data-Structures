#Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
#Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
#Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3  
+ Arr4 =1000,
which is maximum.
  
#CODE:
int maximumSumSubarray(int K, vector<int> &Arr , int N){ 
        int sum=0,maxs=-1e9;
        int i=0,j=0;
        while(j<N)
        {
            sum=sum+Arr[j];
            if(j-i+1<K)
                j++;
            else if(j-i+1==K)
            {
                maxs=max(sum,maxs);
                sum=sum-Arr[i];
                i++;
                j++;
            }
        }
        return maxs;
    }
