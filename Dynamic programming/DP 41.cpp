/*Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. 
The cost of matrix multiplication is defined as the number of scalar multiplications. 
A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 
2nd matrix is arr[1] * arr[2], and so on.


Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: 6000  
There are only two matrices of dimensions 10x20 and 20x30. So there 
is only one way to multiply the matrices, cost of which is 10*20*30 */


//CODE:
int solve(vector<int> &a,int i,int j)
{
    if(i==j)
        return 0;
    int k;
    int mini=1e9;
    int count;
    for(int k=i;k<j;k++)
    {
        count=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
        if(count<mini)
            mini=count;
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return solve(arr,1,N-1);
}

