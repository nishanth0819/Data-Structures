/*Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through limited cells only. Also you can move only up, down, left and right. If found output the distance else -1. 
s represents ‘source’ 
d represents ‘destination’ 
* represents cell you can travel 
0 represents cell you can not travel 
This problem is meant for single source and destination.
Examples: 
 

Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1*/

//CODE:

int find(vector<vector<char>> path,int i,int j,int n)
{
    vector<vector<char>> dir={{-1,0},{0,1},{0,-1},{1,0}};
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{i,j},0});
    while(q.empty()==false)
    {
        int size=q.size();
        while(size--)
        {
            auto node=q.front();
            q.pop();
            int i=node.first.first;
            int j=node.first.second;
            int cost=node.second;
            if(path[i][j]=='d')
               return cost;
            for(auto di:dir)
            {
                int x=i+di[0];
                int y=j+di[1];
                if(x>=0 && x<n && y>=0 && y<n && path[i][j]!='0' && vis[x][y]==false)
                {
                    q.push({{x,y},cost+1});
                    vis[x][y]=true;
                }
            }
        }
    }
    return -1;
}
int findshotrest(vector<vector<char>> &path)
{
    int n=path.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(path[i][j]=='s')
               return find(path,i,j,n);
        }
    }
    return -1;
}
