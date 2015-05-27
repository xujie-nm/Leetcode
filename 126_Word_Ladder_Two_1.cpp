#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
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
    res = findLadders(start, end, dict);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
