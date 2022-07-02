//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that 
// is either directly below or diagonally left/right. Specifically, the next element from position
// (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum underlined below:
// [[2,1,3],      [[2,1,3],
//  [6,5,4],       [6,5,4],
//  [7,8,9]]       [7,8,9]]
// Example 2:
// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is underlined below:
// [[-19,57],
//  [-40,-5]]
// Example 3:
// Input: matrix = [[-48]]
// Output: -48 

// Constraints:
// n == matrix.length
// n == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

//RECURSIVE CODE:(TLE)

    int find(vector<vector<int>> &mat,int i,int j,int rows,int col)
    {
        if(i==rows-1)
            return mat[i][j];
        int dialeft=1e9;
        if(j-1>=0 && j-1<col)
            dialeft=mat[i][j]+find(mat,i+1,j-1,rows,col);
        int down=mat[i][j]+find(mat,i+1,j,rows,col);
        int diaright=1e9;
        if(j+1<col)
            diaright=mat[i][j]+find(mat,i+1,j+1,rows,col);
       return min(dialeft,min(down,diaright));      
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix[0].size();
        int col=matrix.size();
        int mini=1e9;
        for(int i=0;i<col;i++)
        {
            int temp=find(matrix,0,i,rows,col);
            if(temp<mini)
                mini=temp;
        }
        return mini;
    }

//DP CODE(BOTTOM-UP)
  vector<vector<int>> dp;
    int find(vector<vector<int>> &mat,int i,int j,int rows,int col)
    {
        if(i==rows-1)
            return mat[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int dialeft=1e9;
        if(j-1>=0 && j-1<col)
            dialeft=mat[i][j]+find(mat,i+1,j-1,rows,col);
        int down=mat[i][j]+find(mat,i+1,j,rows,col);
        int diaright=1e9;
        if(j+1<col)
            diaright=mat[i][j]+find(mat,i+1,j+1,rows,col);
       return dp[i][j]=min(dialeft,min(down,diaright));      
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix[0].size();
        int col=matrix.size();
        int mini=1e9;
        dp.resize(rows+1,vector<int>(col+1,-1));
        for(int i=0;i<col;i++)
        {
            int temp=find(matrix,0,i,rows,col);
            if(temp<mini)
                mini=temp;
        }
        return mini;
    }
