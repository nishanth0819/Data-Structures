#Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
#Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 #Input:
  Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 
  
#CODE:
  
  vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        queue<long long> q;
        vector<long long> res;
        int i=0,j=0;
        while(j<N)
        {
            if(A[j]<0)
               q.push(A[j]);
            if(j-i+1<K)
                j++;
            else if(j-i+1==K)
            {
                if(q.size()!=0)
                {
                res.push_back(q.front());
                if(A[i]==q.front())
                     q.pop();
                }
                else
                    res.push_back(0);
                i++;
                j++;
            }
        }
        return res;
                                                 
 }

 
  
