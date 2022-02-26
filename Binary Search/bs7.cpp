/*

Given a sorted integer array, find the floor and ceiling of a given number in it. For a given number x, floor(x) is the largest integer in the array less than or equal to x, and ceil(x) is the smallest integer in the array greater than or equal to x.

The solution should return the (floor, ceil) pair. If the floor or ceil doesn't exist, consider it to be -1.

Input: nums[] = [1, 4, 6, 8, 9], x = 2
Output: (1, 4)
Explanation: The floor is 1 and ceil is 4

Input: nums[] = [1, 4, 6, 8, 9], x = 6
Output: (6, 6)
Explanation: The floor is 6 and ceil is 6

Input: nums[] = [-2, 0, 1, 3], x = 4
Output: (3, -1)
Explanation: The floor is 3 and ceil doesn't exist

*/

class Solution
{
public:
   int findfloor(vector<int> const &arr,int x)
   {
   	    int start=0;
   	    int end=arr.size()-1;
   	    int res=-1;
   	    while(start<=end)
   	    {
   	    	int mid=end+(start-end)/2;
   	    	if(arr[mid]==x)
   	    	    return arr[mid];
   	    	else if(arr[mid]<x)
   	    	{
   	    		start=mid+1;
   	    		res=arr[mid];
   	    	}
   	    	else if(arr[mid]>x)
   	    	   end=mid-1;
   	    }
   	    return res;
   }
    int findceil(vector<int> const arr,int x)
   {
   	    int start=0;
   	    int end=arr.size()-1;
   	    int res=-1;
   	    while(start<=end)
   	    {
   	    	int mid=end+(start-end)/2;
   	    	if(arr[mid]==x)
   	    	    return arr[mid];
   	    	else if(arr[mid]<x)
   	    	{
   	    		start=mid+1;
   	    	}
   	    	else if(arr[mid]>x)
   	    	{
   	    	   res=arr[mid];
   	    	   end=mid-1;
   	    	}
   	    }
   	    return res;
   }
	pair<int,int> findFloorAndCeil(vector<int> const &nums, int x)
	{
		// Write your code here...
		pair<int,int> g;
		g.first=findfloor(nums,x);
		g.second=findceil(nums,x);
		return g;
	}
};
