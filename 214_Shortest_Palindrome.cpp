#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//TLE
string shortestPalindrome(string s){
    if(s.size() == 1)
        return s;
    int maxSubPalSize = 0;
    for (int i = 1; i < s.size(); i++) {
        int left = i, right = i;
        while(left >= 0 && right < s.size()){
            if(s[left] != s[right])
                break;
            left--;
            right++;
        }
        if(right-left-1 > 1 && right-left-1 > maxSubPalSize){
            maxSubPalSize = right-left-1;
        }
        left = i; right = i+1;
        while(left >= 0 && right < s.size()){
            if(s[left] != s[right])
                break;
            left--;
            right++;
        }
        if(right-left-1 && right-left-1 > maxSubPalSize){
            maxSubPalSize = right-left-1;
        }
    }
    string front;
    for (int i = s.size()-1; i >= (maxSubPalSize == 0 ? maxSubPalSize+1 : maxSubPalSize); i--) {
        front += s[i];
    }
    return front + s;
}

// change
string shortestPalindrome2(string s){
    int len = s.size();
    if(len <= 1)
        return s;
    int max = 1, start, end;
    for(int begin = 0; begin <= len/2;){
        start = begin;
        end = begin;
        //跳出中间相等的部分
        while(end < len-1 && s[end+1] == s[end])
            ++end;
        begin = end+1;
        while(end < len-1 && start > 0 && s[end+1] == s[start-1]){
            ++end;
            --start;
        }
        if(start == 0 && end-start+1 > max)
            max = end-start+1;
    }
    string front = s.substr(max, len - max);
    reverse(front.begin(), front.end());
    return front+s;
}


int main(int argc, const char *argv[])
{
    cout << shortestPalindrome2("aacecaaa") << endl;
    cout << shortestPalindrome2("abcd") << endl;
    cout << shortestPalindrome2("ba") << endl;
    cout << shortestPalindrome2("aabba") << endl;
    cout << shortestPalindrome2("abbacd") << endl;
    return 0;
}
