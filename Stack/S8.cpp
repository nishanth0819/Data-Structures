// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = []
// Output: 0
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
// Example 4:

// Input: matrix = [["1"]]
// Output: 1
// Example 5:

// Input: matrix = [["0","0"]]
// Output: 0

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 0 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

#CODE:

 int find(vector<int> hei)
    {
       stack<pair<int,int>> st1,st2;
        vector<int> nsl,nsr;
        int n=hei.size();
        for(int i=0;i<n;i++)
        {
            if(st1.empty()==true)
                nsl.push_back(-1);
            else if(st1.empty()==false && st1.top().first>=hei[i])
            {
                while(st1.empty()==false && st1.top().first>=hei[i])
                    st1.pop();
                if(st1.empty()==true)
                    nsl.push_back(-1);
                else
                    nsl.push_back(st1.top().second);
            }
            else
                nsl.push_back(st1.top().second);
            st1.push({hei[i],i});
        }
        for(int i=n-1;i>=0;i--)
        {
            if(st2.empty()==true)
                nsr.push_back(n);
            else if(st2.empty()==false && st2.top().first>=hei[i])
            {
                while(st2.empty()==false && st2.top().first>=hei[i])
                    st2.pop();
                if(st2.empty()==true)
                    nsr.push_back(n);
                else
                    nsr.push_back(st2.top().second);
            }
            else
                nsr.push_back(st2.top().second);
            st2.push({hei[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        int maxa=-1e9;
        for(int i=0;i<n;i++)
        {
            maxa=max(maxa,(nsr[i]-nsl[i]-1)*hei[i]);
        }
        return maxa;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> hei(n,0);
        int ans=-1e9;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                    hei[j]=0;
                else
                    hei[j]++;
            }
            ans=max(ans,find(hei));
        }
        return ans;
    }
