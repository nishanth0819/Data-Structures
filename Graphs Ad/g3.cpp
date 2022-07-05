// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0. 

// Example 1:

// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

//CODE:

int find(vector<vector<int>> &grid,int i,int j,int m,int n,vector<vector<bool>> &vis)
    {
        queue<pair<int,int>> q;
        int count=1;
        q.push({i,j});
        vis[i][j]=true;
        vector<vector<int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(q.empty()==false)
        {
            int size=q.size();
            while(size--)
            {
                auto node=q.front();
                q.pop();
                int i=node.first;
                int j=node.second;
                for(auto di:dir)
                {
                    int x=i+di[0];
                    int y=j+di[1];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1 && vis[x][y]==false)
                    {
                        count++;
                        q.push({x,y});
                        vis[x][y]=true;
                    }
                }
                
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        int maxi=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int count=find(grid,i,j,rows,cols,vis);
                    maxi=max(count,maxi);
                }
            }
        }
        return maxi;
        
    }
