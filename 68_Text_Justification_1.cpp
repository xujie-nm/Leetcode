#include <iostream>
#include <string>
#include <vector>
using namespace std;
//我觉得和我的想法一样啊，为什么我的就MLE了
//郁闷，估计就是局部变量使用的太多了吧
vector<string> fullJustify(vector<string> &words, int L){
    vector<string> res;
    int begin = 0;
    while(begin < words.size()){
        int last = begin;
        int linesize = words[begin++].size();
        while(begin < words.size() && linesize + 1 + words[begin].size() <= L){
            linesize += 1+words[begin].size();
            begin++;
        }
        //计算当前可以容纳多少个word

        int spaces = 1, extra = 0;
        if(begin < words.size() && begin != last + 1){
            spaces = (L - linesize) / (begin - last - 1) +1;
            extra = (L - linesize) % (begin - last - 1);
        }
        //计算单词间隔和多余出来的间隔

        res.push_back(words[last++]);
        while(extra--){
            res.back().append(spaces+1, ' ');
            res.back().append(words[last++]);
        }
        //先添加间隙宽的单词
        while(last < begin){
            res.back().append(spaces, ' ');
            res.back().append(words[last++]);
        }
        //在添加剩余的单词
        res.back().append(L-res.back().size(), ' ');
        //最后补全
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> word;
    word.push_back("This");
    word.push_back("is");
    word.push_back("an");
    word.push_back("example");
    word.push_back("of");
    word.push_back("text");
    word.push_back("justification.");

    vector<string> res;
    res = fullJustify(word, 16);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    cout << res.size() << endl;
    cout << res[0].size() << endl;
    return 0;
}
