#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//TLE
vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    sort(p.begin(), p.end());

    if(p.size() > s.size())
    {
        return res;
    }

    for (int i = 0; i < s.size()-p.size()+1; i++) {
        string temp = s.substr(i, p.size());
        sort(temp.begin(), temp.end());
        if(temp == p)
        {
            res.push_back(i);
        }
    }

    return res;
}

// ACCEPT
vector<int> findAnageams1(string s, string p)
{
    std::vector<int> res;
    std::vector<int> freqs(26, 0);

    for (int i = 0; i < p.size(); i++) {
        freqs[p[i]-'a']++;
    }

    for (int l = 0, r = 0, cnt = 0; r < s.size(); r++) {
        if(r-l == p.size() && ++freqs[s[l++]-'a'] > 0)
            cnt--;
        if(freqs[s[r]-'a']-- > 0 && ++cnt == p.size())
            res.push_back(l);
    }

    return res;
}


int main(int argc, char const* argv[])
{
    string s = "cbaebabacd";
    string p = "abc";
    std::vector<int> res;
    res = findAnagrams(s, p);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
