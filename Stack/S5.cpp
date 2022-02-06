// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in 
// the array, which means you could search circularly to find its next greater number. If it doesn't
//   exist, return -1 for this number.

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// Constraints:

// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109

#CODE:
vector<int> nextGreaterElements(vector<int>& arr) {
        vector<int> res;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            while(j<n)
            {
                if(arr[i]<arr[j])
                {
                    res.push_back(arr[j]);
                    break;
                }
                j++;
            }
            if(j==n)
            {
                j=0;int flag=0;
                while(j<i)
                {
                    if(arr[j]>arr[i])
                    {
                        res.push_back(arr[j]);
                        flag=1;
                        break;
                    }
                    j++;
                }
                if(flag==0)
                    res.push_back(-1);
            }
            
        }
        return res;
        
    }

#OPTIMIZED CODE:


vector<int> nextGreaterElements(vector<int>& arr) {
        vector<int> res;
       stack<int> st;
        int n=arr.size();
      for(int i=n-1; i>=0; --i){            
            while(!st.empty() and arr[i]>=st.top())
                st.pop();
            st.push(arr[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()==true)
                res.push_back(-1);
            else if(st.top()<=arr[i])
            {
                while(st.empty()==false and st.top()<=arr[i])
                    st.pop();
                if(st.empty()==true)
                    res.push_back(-1);
                else
                    res.push_back(st.top());
            }
            else
                res.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
