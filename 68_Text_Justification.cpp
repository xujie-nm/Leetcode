#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string> &word, int L){
    vector<string> res;

    for(int i = 0; i < word.size(); ){
        int temp_L = 0;
        int spaces = 0;
        int j = i;
        int temp_i = i;
        while(j < word.size()){
            if(temp_L + word[j].size() + spaces < L){
                temp_L += word[j].size();
                j++;
                spaces++;
            }else
                break;
        }
        j = j >= word.size() ? word.size()-1 : j;

        int tt = (j-i-1) > 0 ? j-i-1 : 1;
        int left_spaces = (L - temp_L)%tt;
        int gap = (L-temp_L)/tt;
        string temp;
        string string_gap(gap, ' ');

        if(i==j){
            temp += word[i] + string_gap;
        }
        while(left_spaces-- > 0 && i < j){
            temp += word[i] + string_gap + ' ';
            i++;
        }
        while(i < j){
            temp += word[i] + string_gap;
            i++;
        }
        res.push_back(temp.substr(0, L));
        if(temp_i == word.size() - 1)
            break;
        i = j;
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
