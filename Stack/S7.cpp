/*
Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4
Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#BRUTE-FORCE:

int largestRectangleArea(vector<int>& heights) {
        int res=-1e9;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            int minh=1e9;
            for(int j=i;j<n;j++)
            {
                minh=min(minh,heights[j]);
                int wid=j-i+1;
                res=max(res,wid*minh);
            }
        }
        return res;
    }

#OPTIMIZED CODE:

int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> nsl(n), nsr(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and heights[i] <= heights[st.top()])
                st.pop();
            if(st.empty()) nsl[i] = 0;
            else nsl[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and heights[i] <= heights[st.top()])
                st.pop();
            if(st.empty()) nsr[i] = n-1;
            else nsr[i] = st.top() - 1;
            st.push(i);
        }
        for(int i = 0; i < n; i++)
            ans = max(ans, (nsr[i] - nsl[i] + 1) * heights[i]);
        return ans;
    }
