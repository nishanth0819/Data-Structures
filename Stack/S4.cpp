// The next greater element of some element x in an array is the first greater element that is to the
//  right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next
//  greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this
//  query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

// Constraints:

// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.
 
CODE:
vector<int> find(vector<int> &arr1,vector<int> &arr2)
{
    vector<int> res;
    for(int i=0;i<arr1.size();i++)
    {
        int cval=arr1[i];
        int j=0;
        int flag=0;
        while(arr2[j]!=cval)
            j++;
        for(int k=j+1;k<arr2.size();k++)
        {
            if(cval<arr2[k])
            {
                res.push_back(arr2[k]);
                flag=1;
                break;
            }
        }
        if(flag==0)
           res.push_back(-1);
    }
    return res;
}

OPTIMIZED CODE:

vector<int> find(vector<int> &arr1,vector<int> &arr2)
{
    vector<int> res;
    stack<int> s;
    unordered_map<int,int> mp;
    for(int i=arr2.size()-1;i>=0;i--)
    {
        if(s.empty()==true)
            mp[arr2[i]]=-1;
        else if(s.top()<=arr2[i])
        {
            while(s.empty()==false and s.top()<=arr2[i])
                s.pop();
            if(s.empty()==true)
                mp[arr2[i]]=-1;
            else
               mp[arr2[i]]=s.top();
        }
        else
           mp[arr2[i]]=s.top();
        s.push(arr2[i]);
    }
    for(int i=0;i<arr1.size();i++)
    {
        res.push_back(mp[arr1[i]]);
    }
    
    return res;
}
