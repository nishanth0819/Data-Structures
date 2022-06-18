/*Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with positive number.
 

Example 1:

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2
Example 2:

Input: 
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output:
5 -5 2 -2 4 -8 7 1 8 0 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the array of integers arr[] and n as parameters. You need to modify the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
 

Constraints:
1 ≤ N ≤ 107
-106 ≤ Arr[i] ≤ 107*/

//CODE:
void rearrange(int arr[], int n) {
	    // code here
	    queue<int> q1,q2;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0)
	           q1.push(arr[i]);
	        else
	          q2.push(arr[i]);
	    }
	    vector<int> res;
	    while(q1.empty()==false && q2.empty()==false)
	    {
	        res.push_back(q1.front());
	        res.push_back(q2.front());
	        q1.pop();
	        q2.pop();
	    }
	    while(q1.empty()==false)
	    {
	        res.push_back(q1.front());
	        q1.pop();
	    }
	    while(q2.empty()==false)
	    {
	        res.push_back(q2.front());
	        q2.pop();
	    }
	    for(int i=0;i<n;i++)
	    {
	        arr[i]=res[i];
	    }
	}
