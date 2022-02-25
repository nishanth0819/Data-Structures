//An element at index i in a correctly sorted order can be misplaced by the ± 1 position, i.e., it can be present at index i-1 or i or i+1 in the input array.

/*Input:
 
nums = [2, 1, 3, 5, 4, 7, 6, 8, 9]
target = 5
 
Output: Element 5 found at index 3
 
 
Input:
 
nums = [2, 1, 3, 5, 4, 7, 6, 8, 9]
target = 10
 
Output: Element not found in the array*/


//CODE:

int find(vector<int> arr,int target)
{
    int low=0;
    int high=arr.size()-1;
    while(low<=high)
    {
        int mid=low+((high-low)/2);
        if(arr[mid]==target)
            return mid;
        if(arr[mid+1]==target && mid+1<=high)
             return mid+1;
        if(arr[mid-1]==target && mid-1>=low)
             return mid-1;
        if(arr[mid]>target)
           high=mid-2;
        else
           low=mid+2;
    }
    return -1;
}
