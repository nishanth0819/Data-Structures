/*Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. 
As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.
Examples: 
 

Input : arr[] = {0, 0, 1, 1, 1, 1} 
Output : 2

Input : arr[] = {1, 1, 1, 1,, 1, 1}
Output : 0*/

//CODE:

int find(int arr[],int low,int high,int val)
{
    int res=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==val)
         {
             res=mid;
             high=mid-1;
         }
        else if(arr[mid]>val)
            high=mid-1;
        else
           low=mid+1;
    }
    return res;
}
int findinf(int arr[])
{
    int low=0,high=1;
    while(arr[high]==0)
    {
        low=high;
        high=high*2;
    }
    return find(arr,low,high,1);
}
