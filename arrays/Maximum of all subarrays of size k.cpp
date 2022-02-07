// You are given an array of integers nums, there is a sliding window of size k which
// is moving from the very left of the array to the very right. You can only see the 
// k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window. 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Example 3:

// Input: nums = [1,-1], k = 1
// Output: [1,-1]
// Example 4:

// Input: nums = [9,11], k = 2
// Output: [11]
// Example 5:

// Input: nums = [4,-2], k = 2
// Output: [4]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


#CODE:

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n=A.size();
    int i=0,j=0;
    int k=B;
    vector<int> result;
    vector<int> temp;
    while(j<n)
    {
       temp.push_back(A[j]);
       if(j-i+1<k)
           j++;
        else if(j-i+1==k)
        {
           result.push_back(*max_element(temp.begin(),temp.end()));
           temp.erase(temp.begin());
           i++;
           j++;
        }
    }
    return result;
}


#OPTIMIZED CODE:


vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;
    int n=A.size();
    vector<int> res;
    int i=0,j=0;
    int k=B;
    while(j<n)
    {
        while(dq.empty()==false && A[j]>dq.back())
                        dq.pop_back();
         dq.push_back(A[j]);
         if(j-i+1<k)
             j++;
        else if(j-i+1==k)
        {
            res.push_back(dq.front());
            if(A[i]==dq.front())
                dq.pop_front();
            i++;
            j++;
        }
    }
    return res;
}

