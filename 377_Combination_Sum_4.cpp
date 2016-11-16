#include <string>
#include <vector>
#include <iostream>

using namespace std;

// backtracking TLE
void helper(vector<int>&nums, int target, int cur, int&res)
{
	if(cur > target)
	{
		return;
	}
	else if(cur == target)
	{
		res++;
		return;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		helper(nums, target, cur+nums[i], res);
	}
}

int combinationSum4(vector<int>& nums, int target)
{
	int res = 0;
	int cur = 0;
	helper(nums, target, cur, res);

	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> nums{1,2,3};
	cout << "result: " << combinationSum4(nums, 4) << endl;
	return 0;
}
