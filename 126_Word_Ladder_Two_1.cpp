#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

map<string, unordered_set<string> >&
buildTree(string& start, string& end, unordered_set<string> &dict){
    //这里最重要的地方就在于如何建立parents
    static map<string, unordered_set<string> > parents;
    parents.clear();

    unordered_set<string> level[3];
    unordered_set<string> *previousLevel = &level[0];
    //和前面一层相差一个字符的候选集
    unordered_set<string> *currentLevel = &level[1];
    //当前层的候选集
    unordered_set<string> *newLevel = &level[2];
    //产生新的候选集
    unordered_set<string> *p = NULL;
    currentLevel->insert(start);

    bool reachEnd = false;

    while(!reachEnd){//判断是否到达end字符
        newLevel->clear();//清空新的层
        for(auto it = currentLevel->begin(); it!=currentLevel->end(); it++){//遍历当前层
            for (int i = 0; i < it->size(); i++) {
                string newWord = *it;
                for(char c='a'; c<='z'; c++){//产生新的一个相差一个字符的word
                    newWord[i] = c;
                    if(newWord == end){
                        reachEnd = true;
                        parents[*it].insert(end);
                        continue;
                    }
                    if(dict.count(newWord)==0 || currentLevel->count(newWord)>0 || previousLevel->count(newWord)>0){
                        //如果字典里面没有字符、
                        //或者当前层和上一层有这个字符
                        //不做任何操作继续
                        continue;
                    }
                    newLevel->insert(newWord);
                    parents[*it].insert(newWord);
                    //如果字典里有这个字符，且前两层没有这个word
                    //就把word加入新的一层
                    //而*it的下一个字符就有可能是newWord
                }
            }
        }
        if(newLevel->empty())//如果新层为空，说明start到不了end
            break;
        p = previousLevel;
        previousLevel = currentLevel;
        currentLevel = newLevel;
        newLevel = p;
        //后移
    }
    if(!reachEnd){
        parents.clear();//接上面的break，说明无法到达end，返回空map
    }
    return parents;
}

void generatePath(string start, string end,
        map<string, unordered_set<string> > &parents,
        vector<string> path,
        vector<vector<string> > &paths){
    //parents里存放的是dict中的每一个word的下一个在dict中的word是那个
    if(parents.find(start) == parents.end()){//到达end
        if(start == end)
            paths.push_back(path);
        return;
    }

    for(auto it=parents[start].begin(); it!=parents[start].end(); it++){
        //回溯
        path.push_back(*it);
        generatePath(*it, end, parents, path, paths);
        path.pop_back();
    }
}

vector<vector<string> >
findLadders(string start, string end, unordered_set<string> &dict){
    vector<vector<string> > ladders;
    vector<string> ladder;
    ladder.push_back(start);
    if(start == end){
        ladder.push_back(end);
        ladders.push_back(ladder);
        return ladders;
    }

    map<string, unordered_set<string> > &
        parents = buildTree(start, end, dict);

    if(parents.size() <= 0)
        return ladders;

    generatePath(start, end, parents, ladder, ladders);
    return ladders;
}


// faster solution
// 利用这个函数来找到nexts
bool findLaddersHelper(unordered_set<string> &beginWords,
                       unordered_set<string> &endWords,
                       unordered_set<string> &dict,
                       unordered_map<string, vector<string> > &nexts,
                       bool &IsBegin){
    IsBegin = !IsBegin;
    if(beginWords.empty())
        return false;
    // 这一步是降低复杂度的
    if(beginWords.size() > endWords.size())
        return findLaddersHelper(endWords, beginWords, dict, nexts, IsBegin);
    // 第一步，先把dict中的words1和words2去掉
    for(auto it = beginWords.begin();
             it != beginWords.end();
             ++it){
        dict.erase(*it);
    }
    for(auto it = endWords.begin();
             it != endWords.end();
             ++it){
        dict.erase(*it);
    }

    unordered_set<string> tempWords;
    bool reach = false;
    for(auto it = beginWords.begin();
             it != beginWords.end();
             ++it){
        string word = *it;
        // 下面的两个for是改变word中的一个字母，
        // 看改变后的word是否存在于words2或者dict中
        for(auto ch = word.begin();
                 ch != word.end();
                 ++ch){
            char temp = *ch;
            for(*ch = 'a'; *ch <= 'z'; ++(*ch)){
                if(*ch != temp)
                    if(endWords.find(word) != endWords.end()){
                        // 到了终点
                        reach = true;
                        // 这一步是为了防止nexts里出现环
                        // 如果是单纯地找next会出现重复，这样就会有环
                        // 通过一个bool值来限定，把重复的去掉
                        IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                    }else if(!reach && dict.find(word) != dict.end()){
                        // 如果没到最后终点，但是这个单词是中间的一个，继续
                        tempWords.insert(word);
                        IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                    }
            }
            *ch = temp;
        }
    }
    return reach || findLaddersHelper(endWords, tempWords, dict, nexts, IsBegin);
}

// 回溯找路径
void getPath(string beginWord,
             string &endWord,
             unordered_map<string, vector<string> > &nexts,
             vector<string> &path,
             vector<vector<string> > &paths){
    if(beginWord == endWord)
        paths.push_back(path);
    else{
        for(auto it = nexts[beginWord].begin();
                 it != nexts[beginWord].end();
                 ++it){
            path.push_back(*it);
            getPath(*it, endWord, nexts, path, paths);
            path.pop_back();
        }
    }
}

vector<vector<string> > findLadders2(string beginWord, string endWord, unordered_set<string> &wordList){
    vector<vector<string> > paths;
    vector<string> path(1, beginWord);
    if(beginWord == endWord){
        paths.push_back(path);
        return paths;
    }

    unordered_set<string> words1, words2;
    words1.insert(beginWord);
    words2.insert(endWord);

    unordered_map<string, vector<string> > nexts;
    bool words1IsBegin = false;

    if(findLaddersHelper(words1, words2, wordList, nexts, words1IsBegin))
        getPath(beginWord, endWord, nexts, path, paths);

    return paths;
}


int main(int argc, const char *argv[])
{
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    vector<vector<string> > res;
    res = findLadders2(start, end, dict);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
