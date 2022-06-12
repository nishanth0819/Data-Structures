/*

Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)
*/

//CODE:

	pair<int,int> findPair(vector<int> const &nums, int target)
	{
		// Write your code here...
		pair<int,int> res;
		unordered_map<int,int> mp;
		int n=nums.size();
		for(int i=0;i<n;i++)
		{
			if(mp.find(target-nums[i])!=mp.end())
			{
				res.first=nums[mp[target-nums[i]]];
				res.second=nums[i];
				return res;
			}
			mp[nums[i]]=i;
		}
		res.first=-1;
		res.second=-1;
		return res;
	}
