//Finding an element in Infinite Sorted Array


//CODE:

int find(int arr[],int low,int high,int val)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==val)
            return mid;
        else if(arr[mid]>val)
            high=mid-1;
        else
           low=mid+1;
    }
    return -1;
}
int findinf(int arr[],int key)
{
    int val=arr[0];
    int high=1;
    int low=0;
    while(val<key)
    {
        low=high;
        high=high*2;
        val=arr[high];
    }
   return find(arr,low,high,key);
}
