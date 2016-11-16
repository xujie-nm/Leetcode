#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// binary search
int kthSmallest(vector<vector<int> >& matrix, int k)
{
	int n = matrix.size();
	int left = matrix[0][0], right = matrix[n-1][n-1];
	int mid = 0;

	while(left < right)
	{
		mid = left + (right-left)/2;
		int count = 0;
		for (int i = 0; i < n; ++i)//找出每一行小于mid的那些数的个数
		{
			int pos = upper_bound(matrix[i].begin(),matrix[i].end(), mid) - matrix[i].begin();
			count += pos;
		}

		if(count < k)
		{
			left = mid+1;
		}
		else
		{
			right = mid;
		}

	}
	return left;
}

// priority_queue
int kthSmallest_1(vector<vector<int> >& matrix, int k)
{
	int n = matrix.size();

	auto cmp = [&matrix] (const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];

	};

	priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> que(cmp);
	
	que.emplace(0,0);
	int result;
	while(k-- && !que.empty())
	{
		auto t = que.top(); 
		que.pop();

		result = matrix[t.first][t.second];
		if(t.first+1 < n)
		{
			que.emplace(t.first+1, t.second);
		}
		if(t.first==0 && t.second+1 < n)
		{
			que.emplace(t.first, t.second+1);
		}

	}	
	return result;
}

int main(int argc, char const* argv[])
{

	
	std::vector<int> line1{1,5,9};
	std::vector<int> line2{10,11,13};
	std::vector<int> line3{12,13,15};
	std::vector<std::vector<int> > matrix{line1,line2,line3};

	cout << "result: " << kthSmallest(matrix, 8) << endl;

    return 0;
}
