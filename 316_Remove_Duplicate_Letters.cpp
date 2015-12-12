#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// stack
string removeDuplicateLetters(string s){
    unordered_map<char, int> counts;
    string res;
    stack<char> stk;
    vector<bool> visited(26, false);

    // 计算出每个字母出现的次数
    for (int i = 0; i < s.size(); i++) {
        counts[s[i]]++;
    }

    for (int i = 0; i < s.size(); counts[s[i]]--, i++) {
        if(visited[s[i] - 'a'] || 
           (!stk.empty() && stk.top() == s[i]))
            continue;

        // 如果当前栈不空，
        // 且与当前字母逆序
        // 而且count是大于0的则pop
        // (stk.top() > s[i]保证字典序)
        // 这里counts大于0而不是大于1，是因为
        // 每次循环都要对应的字符减一
        // 所以最后一个的时候已经减到0
        while(!stk.empty() && 
              stk.top() > s[i] && 
              counts[stk.top()] > 0){
            visited[stk.top() - 'a'] = false;
            stk.pop();
        }
        stk.push(s[i]);
        visited[s[i] - 'a'] = true;
    }
    
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

string removeDuplicateLetters2(string s){
    int kAdded = INT_MAX;
    unordered_map<char, int> counts;
    for (int i = 0; i < s.size(); i++) {
        counts[s[i]]++;
    }

    string res;
    int begin = 0;
    int end;
    // 每次循环都要找到那个需要插入的字符
    while(begin < s.size()){
        // 如果这个字符已经加入到最后的结果中，跳过
        if(counts[s[begin]] == kAdded){
            ++begin;
            continue;
        }

        // 寻找当前需要插入的字符
        end = begin;
        char minChar = s[end];
        int posChar = end;
        while(end < s.size() && counts[s[end]] > 1){
            if(counts[s[end]] != kAdded)  {
                if(s[end] < minChar){
                    minChar = s[end];
                    posChar = end;
                }
                --counts[s[end]];
            }      
            ++end;
        }

        // 不是这个字符
        // 而且连续下降
        if(end < s.size() && s[end] < minChar){
            begin = end;
            continue;
        }

        // 把减去的加回来
        for (int i = posChar + 1; i < end; i++) {
            if(counts[s[i]] == kAdded)
                continue;
            ++counts[s[i]];
        }
        counts[minChar] = kAdded;
        begin = posChar + 1;
        res.push_back(minChar);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    string s = "cbacdcbc";
    cout << removeDuplicateLetters2(s) << endl;
    return 0;
}
