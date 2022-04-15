/*Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:

Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes arr[] and n as input parameters and returns the minimum possible sum. As the number can be large, return string presentation of the number without leading zeroes.
 

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)

*/

//CODE:

string solve(int arr[], int n) {
         priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        stack<int> s1,s2;
        while(pq.size()>0)
        {
            if(pq.size()>0)
              {
                  s1.push(pq.top());
                  pq.pop();
              }
            if(pq.size()>0)
            {
                s2.push(pq.top());
                pq.pop();
            }
        }
        int sum=0,carry=0;
        string res;
        vector<int> temp;
        while(s1.size() || s2.size() || carry)
        {
            sum=0;
            if(s1.size()!=0)
             {
                 sum=sum+s1.top();
                 s1.pop();
             }
             if(s2.size()!=0)
             {
                 sum=sum+s2.top();
                 s2.pop();
             }
             sum=sum+carry;
             carry=sum/10;
             temp.push_back(sum%10);
        }
     reverse(temp.begin(),temp.end());
      if(temp[0]==0)
      {
        for(int i=1;i<temp.size();i++)
        {
            res=res+to_string(temp[i]);
        }
      }
      else
      {
        for(int i=0;i<temp.size();i++)
        {
            res=res+to_string(temp[i]);
        }
      }
      return res;
    }
