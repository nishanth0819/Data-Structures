/*Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the function find3Numbers() which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet in the array arr[] which sums up to X and False otherwise.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)*/

//CODE(gives TLE)
bool find3Numbers(int a[], int n, int X)
    {
        //Your Code Here
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(a[i]+a[j]+a[k]==X)
                        return true;
                }
            }
        }
        return false;
    }
//OPTIMIZED CODE:
   bool find3Numbers(int a[], int n, int X)
    {
        //Your Code Here
        unordered_map<int,int> mp;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int sum=a[i]+a[j];
               mp[sum]++;
            }
        }
        for(int k=0;k<n;k++)
        {
            if(mp.find(X-a[k])!=mp.end())
               return true;
        }
        return false;
    }
