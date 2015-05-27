#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    int res = 1;
    string flag = "";
    queue<string> level;
    level.push(beginWord);
    level.push(flag);
    while(!level.empty()){
        string temp = level.front();
        level.pop();
        if(temp == endWord)
            return res;
        if(temp ==flag && level.back() != flag){
            res++;
            level.push(flag);
            continue;
        }
        for (int i = 0; i < temp.size(); i++) {
            string temp1 = temp;
            for(char c='a'; c<='z'; c++){
                temp1[i] = c;
                if(wordDict.count(temp1)>0){
                    level.push(temp1);
                    wordDict.erase(temp1);
                }
            }
        }
    }
    return 0;
}


int main(int argc, const char *argv[])
{
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("cog");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("hit");
    dict.insert("lot");
    dict.insert("log");
    //dict.insert("a");
    //dict.insert("b");
    //dict.insert("c");

    cout << ladderLength("hit", "cog", dict) << endl;
    return 0;
}
