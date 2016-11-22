#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> lexicalOrder(int n)
{
	vector<int> res;

	int cur = 1;
	while(res.size() < n)
	{
		res.push_back(cur);
		cur *= 10;
		while(cur > n)
		{
			cur /= 10;
			cur ++;
			while(cur%10 == 0)
			{
				cur /= 10;
			}
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> res;
	res = lexicalOrder(13);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << ", ";
	}
	cout << endl;
	return 0;
}
