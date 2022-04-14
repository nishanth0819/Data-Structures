/*You have been given an array/list of ‘N’ integers. Now you are supposed to find the K-th largest sum of the subarray.
Please note that a subarray is the sequence of consecutive elements of the array.
Input Format :
The first line contains an integer ‘T’ denoting the number of test cases. Then each test case follows.
The first input line of each test case contains two space-separated integers ‘N’ and ‘K’.
The second input line of each test case contains ‘N’ space-separated integers denoting the elements of the given array.
Output Format :
For each test case, print the K-th largest sum subarray.

The output of each test case will be printed in a separate line.

Note: You are not required to print the expected output; it has already been taken care of. Just implement the function.
Constraints :
1 <= T <= 50
1 <= N <= 100
1 <= K <= (N * (N + 1)) / 2
-1000 <= ARR[i] <= 1000

Where ‘T’ is the number of test cases, ‘N’ is the length of the given array/list, ‘K’ is the given integer and ARR[i] denotes the i-th element of the given array/list.

Time limit: 1 sec
Sample Input 1 :
2
3 3
3 -2 5
2 2
4 1
Sample output 1 :
3
4
Explanation of Sample output 1 :
For the first test case, 
Sum of [0, 0] = 3
Sum of [0, 1] = 1
Sum of [0, 2] = 6
Sum of [1, 1] = -2
Sum of [1, 2] = 3
Sum of [2, 2] = 5
All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

For the second test case, 
Sum of [0, 0] = 4
Sum of [0, 1] = 5
Sum of [1, 1] = 1
All sum of subarrays are {5, 4, 1} where the second largest element is 4.
Sample Input 2 :
2
4 10
5 4 -8 6
3 1
1 2 3
Sample output 2 :
-8
6
Explanation of Sample output 2 :
For the first test case, among the sum of all the subarray, the tenth-largest sum will be -8.

For the second test case, among the sum of all the subarray, the largest sum will be 6.*/


//CODE:

int find(vector<int> &arr,int i,int j)
{
	int sum=0;
	for(int k=i;k<=j;k++)
		sum=sum+arr[k];
    return sum;
}
int getKthLargest(vector<int> &arr, int k)
{
          int n=arr.size();
	priority_queue<int,vector<int>,greater<int>> pq;
	  vector<int> res;
       for(int i=0;i<n;i++)
	   {
		   for(int j=i;j<n;j++)
		   {
			   res.push_back(find(arr,i,j));
		   }
	   }
	int n1=res.size();
	for(int i=0;i<n1;i++)
	{
		pq.push(res[i]);
		if(pq.size()>k)
			pq.pop();
	}
	return pq.top();
	
}
