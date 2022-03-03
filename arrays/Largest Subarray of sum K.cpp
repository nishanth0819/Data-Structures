/*Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 
4*/

//CODE:

int find(vector<int> arr,int val)
{
    int i=0,j=0;
    int sum=0;
    int k=arr.size();
    int res=0;
    while(j<k)
    {
        sum=sum+arr[j];
        if(val>sum)
          j++;
        if(sum==val)
        {
            res=max(res,j-i+1);
            j++;
        }
        if(sum>val)
        {
            while(sum>val)
             {
                 sum=sum-arr[i];
                 i++;
             }
             j++;
        }
    }
    return res;
}
