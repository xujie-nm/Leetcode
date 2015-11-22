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

// faster solution
// 和126新方法一样的思想
int ladderLengthHelper(unordered_set<string> &beginWords,
                       unordered_set<string> &endWords,
                       unordered_set<string> &wordList,
                       int level){
    if(beginWords.empty())
        return 0;
    if(beginWords.size() > endWords.size())
        return ladderLengthHelper(endWords, beginWords, wordList, level);
    unordered_set<string> tempWords;

    for(auto it = beginWords.begin();
             it != beginWords.end();
             ++it){
        string word = *it;
        for(auto ch = word.begin(); ch != word.end(); ++ch){
            char temp = *ch;
            for(*ch = 'a'; *ch <= 'z'; ++(*ch)){
                if(*ch != temp)
                    if(endWords.find(word) != endWords.end())
                        return level + 1;
                    else if (wordList.find(word) != wordList.end()){
                        wordList.erase(word);
                        tempWords.insert(word);
                    }
            }
            *ch = temp;
        }
    }
    return ladderLengthHelper(endWords, tempWords, wordList, level+1);
}

int ladderLength2(string beginWord, string endWord, unordered_set<string> &wordList){
    if(beginWord == endWord)
        return 1;
    unordered_set<string> beginWords, endWords;
    beginWords.insert(beginWord);
    endWords.insert(endWord);
    wordList.erase(beginWord);
    wordList.erase(endWord);
    return ladderLengthHelper(beginWords, endWords, wordList, 1);
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

    cout << ladderLength2("hit", "cog", dict) << endl;
    return 0;
}
