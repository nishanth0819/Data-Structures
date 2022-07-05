// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

//CODE:

int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dir={{-1,0},{0,1},{0,-1},{1,0}};
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;
        int timer=0;
        while(q.empty()==false)
        {
            int n=q.size();
            while(n--)
            {
            auto node=q.front();
            int i=node.first;
            int j=node.second;
            q.pop();
            for(auto d:dir)
            {
                int x=i+d[0];
                int y=j+d[1];
                if(x>=0 && x<rows && y>=0 && y<cols && grid[x][y]==1)
                {
                    grid[x][y]=2;
                    fresh--;
                    q.push({x,y});
                }
            }
            }
         timer++;
            
        }
        if(fresh==0)
            return timer-1;
        else
            return -1;
            
        
    }
