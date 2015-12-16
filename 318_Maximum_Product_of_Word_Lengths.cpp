#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxProduct(vector<string>& words){
    if(words.size() == 0)
        return 0;
    // 统计每个单词有哪些字母出现了
    vector<uint32_t> bit(words.size());
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            bit[i] |= 1 << (words[i][j] - 'a');
        }
    }
    
    // 如果bit[i] & bit[j]!=0说明所对应的word有相同的字母
    int res = 0;
    for (int i = 0; i < words.size(); i++) {
        for (int j = i+1; j < words.size(); j++) {
            if((bit[i] & bit[j]) == 0){
                res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
    }
    
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};

    cout << maxProduct(words) << endl;
    return 0;
}
