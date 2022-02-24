//Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k
//Input : arr[] = {15, 18, 2, 3, 6, 12}
//Output: 2
//Explanation : Initial array must be {2, 3,
//6, 12, 15, 18}. We get the given array after 
//rotating the initial array twice

//Input : arr[] = {7, 9, 11, 12, 5}
//Output: 4

//Input: arr[] = {7, 9, 11, 12, 15};
//Output: 0


//CODE:
int find(vector<int> arr)
{
    int low=0;
    int high=arr.size()-1;
    int n=arr.size();
    while(low<=high)
    {
        int mid=(low+high)/2;
        int prev=(mid+n-1)%n,next=(mid+1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
              return mid;
        else if(arr[mid]<=arr[high])
            high=mid-1;
        else if(arr[low]<=arr[mid])
             low=mid+1;
    }
    return 0;
}
