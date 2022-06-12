/*

Given two sorted arrays of integers, find a maximum sum path involving elements of both arrays whose sum is maximum. You can start from either array, but can switch between arrays only through its common elements.

Input:

X = [3, 6, 7, 8, 10, 12, 15, 18, 100]
Y = [1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50]

Output: The maximum sum is 199

Explanation: The maximum sum path is 1 —> 2 —> 3 —> 6 —> 7 —> 9 —> 10 —> 12 —> 15 —> 16 —> 18 —> 100

*/

//CODE:

int findMaxPathSum(vector<int> const &arr1, vector<int> const &arr2)
	{
		// Write your code here...
		int m=arr1.size();
		int n=arr2.size();
		int sum1=0,sum2=0,res=0;
		int i=0,j=0;
		while(i<m && j<n)
		{
			if(arr1[i]<arr2[j])
			{
				sum1=sum1+arr1[i];
				i++;
			}
			else if(arr1[i]>arr2[j])
			{
				sum2=sum2+arr2[j];
				j++;
			}
			else
			{
				res=res+max(sum1,sum2)+arr1[i];
				i++;
				j++;
				sum1=0;
				sum2=0;
			}
		}
		if(i<m)
		{
			while(i<m)
			{
				sum1=sum1+arr1[i];
				i++;
			}
		}
		if(j<n)
		{
			while(j<n)
			{
				sum2=sum2+arr2[j];
				j++;
			}
		}
		res=res+max(sum1,sum2);
		return res;
		
	}
