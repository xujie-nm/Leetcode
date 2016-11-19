#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<pair<int, int> > kSamllestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	vector<pair<int, int> > res;
	if(nums1.empty() || nums2.empty() || k <= 0)
		return res;

	auto cmp = [&nums1, &nums2](pair<int, int> left, pair<int, int> right)
	{
		return nums1[left.first] + nums2[left.second] > nums1[right.first] + nums2[right.second];
	};

	priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp) > que(cmp);

	que.push(make_pair(0, 0));
	while(k-- && !que.empty())
	{
		auto temp = que.top();
		que.pop();
		cout << "left: " << nums1[temp.first] << " right: " << nums2[temp.second] << endl;
		res.push_back(make_pair(nums1[temp.first], nums2[temp.second]));
		if(temp.first + 1 < nums1.size())
		{
			que.push(make_pair(temp.first+1, temp.second));
		}
		if(temp.first == 0 && temp.second + 1 < nums2.size())
		{
			que.push(make_pair(temp.first, temp.second+1));
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	std::vector<int> nums1{1,7,11};
	std::vector<int> nums2{2,4,6};
	std::vector<pair<int, int> > res;

	res = kSamllestPairs(nums1, nums2, 4);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << "[" << res[i].first << ", " << res[i].second << "]\n";
		/* code */
	}
	return 0;
}
