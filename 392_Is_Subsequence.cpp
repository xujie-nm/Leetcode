#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//TLE
bool isSubsequence(string s, string t)
{
	map<char, set<int> > charMap;
	for (int i = 0; i < t.size(); ++i)
	{
		charMap[t[i]].insert(i);
	}

	int cur = INT_MIN;
	int temp = INT_MIN;
	for (int i = 0; i < s.size(); ++i)
	{
		temp = cur;	
		cur =  *(charMap[s[i]].lower_bound(cur));
		charMap[s[i]].erase(cur);
		if(temp >= cur)
		{
			return false;
		}
	}

	return true;
}

// faster
bool isSubsequence2(string s, string t)
{
	vector<vector<int> > dp(26);
	for (int i = 0; i < t.size(); ++i)
	{
		dp[t[i]-'a'].push_back(i);
	}

	int bound = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		auto v = dp[s[i]-'a'];
		auto it = lower_bound(v.begin(), v.end(), bound);
		if(it == v.end())
			return false;
		bound = *it + 1;
 	}
 	return true;
}

int main(int argc, char const *argv[])
{
	cout << isSubsequence("leeeeetcode", "ahbgdc") << endl;
	return 0;
}
