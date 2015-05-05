#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool helper(string s1, string s2, string s3, int cur1, int cur2, int cur3){
    if(cur2 == s1.size() && cur2 == s2.size() && cur3 == s3.size())
        return true;

    if(s1[cur1] == s3[cur3] && s2[cur2] == s3[cur3]){
        return helper(s1, s2, s3, cur1+1, cur2, cur3+1) || helper(s1, s2, s3, cur1, cur2+1, cur3+1);
    }else if(s1[cur1] == s3[cur3]){
        return helper(s1, s2, s3, cur1+1, cur2, cur3+1);
    }else if(s2[cur2] == s3[cur3]){
        return helper(s1, s2, s3, cur1, cur2+1, cur3+1);
    }else
        return false;
}

bool isInterleave(string s1, string s2, string s3){
    return helper(s1, s2, s3, 0, 0, 0);
}

int main(int argc, const char *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    cout << isInterleave(s1, s2, s4) << endl;
    return 0;
}
