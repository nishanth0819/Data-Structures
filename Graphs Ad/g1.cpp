/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1*/

//CODE:(BFS)
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        if(grid[0][0]==0)
        {
            q.push({{0,0},1});
            vis[0][0]=true;
        }
        else
            return -1;
        while(q.empty()==false)
        {
            int size=q.size();
            while(size--)
            {
                auto node=q.front();
                int i=node.first.first;
                int j=node.first.second;
                int count=node.second;
                q.pop();
                if(i==n-1 && j==n-1)
                    return count;
                for(auto d:dir)
                {
                    int x=i+d[0];
                    int y=j+d[1];
                    if(x>=0 && y>=0 && x<n && y<n && vis[x][y]==false && grid[x][y]==0){
                        q.push({{x,y},count+1});
                        vis[x][y]=true;
                    }
                }
                    
            }
        }
        return -1;
    }
