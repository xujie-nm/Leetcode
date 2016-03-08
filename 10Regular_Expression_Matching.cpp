#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    bool isMatch(const char *s, const char *p) {
        if (!*p)    return (!*s);
        if ('*' == *(p + 1)) {    
            return (isMatch(s, p + 2) || *s && (*s == *p || '.' == *p) && isMatch(s + 1, p));
        } 
        else {
            if (!*s)    return false;
            return (*s == *p || '.' == *p) ? isMatch(s + 1, p + 1) : false;
        }
   }
};

// More effective recursion
bool helper(string& s, int i, string& p, int j, vector<vector<int> > &memory){
    if(memory[i][j] != -1)
        return memory[i][j];

    if(j == p.length())
        memory[i][j] = (i == s.length());
    else if(j + 1 < p.length() && p[j + 1] == '*')
        memory[i][j] = helper(s, i, p, j + 2, memory) || i < s.length() &&
                       (s[i] == p[j] || p[j] == '.') && helper(s, i+1, p, j, memory);
    else
        memory[i][j] = i < s.length() && (s[i] == p[j] || p[j] == '.') && 
                       helper(s, i+1, p, j+1, memory);

    return memory[i][j];
}

bool isMatch(string s, string p){
    vector<vector<int> > memory(s.length()+1, vector<int>(p.length()+1, -1));
    return helper(s, 0, p, 0, memory);
}

int main(int argc, const char *argv[])
{
    cout << isMatch("aab", "c*a*b") << endl;
    return 0;
}
