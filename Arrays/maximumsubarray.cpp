// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.
// Example 2:

// Input:
// N = 4
// arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// -107 ≤ A[i] ≤ 107

#CODE:

int max_sum(vector<int> arr)
{
    int ms=arr[0],cs=arr[0];
    for(int i=0;i<arr.size();i++)
    {
        cs=max(cs,cs+arr[i]);
        ms=max(cs,ms);
    }
    return ms;
}
