#An array is given, find length of the subarray having maximum sum.
#Input :  a[] = {1, -2, 1, 1, -2, 1}
Output : Length of the subarray is 2
#Input : ar[] = { -2, -3, 4, -1, -2, 1, 5, -3 }
Output : Length of the subarray is 5

int max_sum(vector<int> arr)
{
   int cs=0,ms=-1e9;
   int n=arr.size();
   int start=0,end=0,s=0;
        for(int i=0;i<n;i++)
        {  cs+=arr[i];
             if(ms<cs)
             {
                 start=s;
                 end=i;
               ms=cs;
             }
            if(cs<0)
            {
                cs=0;
                s=i+1;
            }
           
        }
        return end-start+1;
}

