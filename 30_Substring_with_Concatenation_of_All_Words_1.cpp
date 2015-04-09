#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L){
    vector<int> res;
    if(L.size() == 0) return res;
    if(S.size() == 0) return res;
    int wordLen = L[0].size();
    if(S.size() < wordLen) return res;

    unordered_map<string, queue<int> > wordhash;
    unordered_map<string, queue<int> >::iterator it;
    queue<int> Q;
    Q.push(-1);

    for (int i = 0; i < L.size(); i++) {
        it = wordhash.find(L[i]);
        if(it == wordhash.end()){
            wordhash[L[i]] = Q;
        }else{
            it->second.push(-1);
        }
    }

    unordered_map<string, queue<int> > temp = wordhash;
    //记录单词都出现过在S中的第几个位置
    for (int i = 0; i < wordLen; i++) {
        int currWordCnt = 0;
        wordhash = temp;
        for (int index = i; index <= S.size() - wordLen; index += wordLen) {
            it = wordhash.find(S.substr(index, wordLen));
            if(it == wordhash.end()){
                currWordCnt = 0;
            }else{
                int lastPos = it->second.front();
                if(lastPos == -1){
                    //如果是第一次出现
                    currWordCnt++;
                }else if(currWordCnt * wordLen < index - lastPos){
                    //如果小於繼續自加
                    currWordCnt++;
                }else{
                    //如果currwordcnt*wordlen > index - lastpos
                    //这个字符重复出现了，所以重新计算
                    currWordCnt = (index - lastPos)/wordLen;
                }
                it->second.pop();
                it->second.push(index);
                if(currWordCnt == L.size()){
                    res.push_back(index-wordLen*(L.size() - 1));
                }
            }
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    string S = "abababababababababa";
    vector<string> L;
    L.push_back("a");
    L.push_back("b");
    L.push_back("a");
    res = findSubstring(S, L);
    for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
