#include <iostream>
#include <vector>
#include <string>

using namespace std;

int firstUniqueChar(string s)
{
	vector<int> chars(26, 0);
	for (int i = 0; i < s.size(); ++i)
	{
		chars[s[i]-'a']++;
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if(chars[s[i]-'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	cout << firstUniqueChar("leetcode") << endl;
	cout << firstUniqueChar("loveleetcode") << endl;
	return 0;
}
