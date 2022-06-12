/*

Given two sorted integer arrays, `X[]` and `Y[]` of size `m` and `n` each, in-place merge elements of `X[]` with elements of array `Y[]` by maintaining the sorted order, i.e., fill `X[]` with the first `m` smallest elements and fill `Y[]` with remaining elements.

Input :

X[] = [1, 4, 7, 8, 10]
Y[] = [2, 3, 9]

Output:

X[] = [1, 2, 3, 4, 7]
Y[] = [8, 9, 10]

*/

//CODE:

	void merge(vector<int> &arr1, vector<int> &arr2)
	{
		// Write your code here...
		priority_queue<int,vector<int>,greater<int>> pq;
		int n1=arr1.size();
		int n2=arr2.size();
		for(int i=0;i<n1;i++)
		{
			pq.push(arr1[i]);
		}
		for(int i=0;i<n2;i++)
		{
			pq.push(arr2[i]);
		}
		for(int i=0;i<n1;i++)
		{
			arr1[i]=pq.top();
			pq.pop();
		}
		for(int i=0;i<n2;i++)
		{
			arr2[i]=pq.top();
			pq.pop();
		}
	}
