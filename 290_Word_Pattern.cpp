#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string str){
   if(pattern == "" || str == "") 
       return false;

   vector<string> words;
   int first = 0;
   int second = 0;
   while(first <= str.size() && second <= str.size()){
        if(str[second] == ' ' || second == str.size()){
            string temp = str.substr(first, second - first);
            int i = 0, j = temp.size()-1;
            while(temp[i] == ' ' || temp[j] == ' '){
                if(temp[i] == ' ')
                    i++;
                if(temp[j] == ' ')
                    j--;
            }
            words.push_back(temp.substr(i, j-i+1));
            first = second;
            second++;
        }else
            second++;
   }

   if(words.size() != pattern.size())
       return false;
   unordered_map<char, string> hash;
   for (int i = 0; i < pattern.size(); i++) {
       if(hash.count(pattern[i]) == 0){
            hash[pattern[i]] = words[i];
       }else{
            if(hash[pattern[i]] != words[i]){
                return false;
            }
       }
   }


   // 再进行检查一遍，检查有没有相同的word对应不同的parttern
   for(unordered_map<char, string>::iterator it = hash.begin(); it != hash.end(); ++it){
       for(unordered_map<char, string>::iterator it1 = it; it1 != hash.end(); ++it1){
           if(it->second == it1->second && it->first != it1->first){
               return false;
           }
       }
   }

   return true;
}

// concise solution
bool wordPattern2(string pattern, string str){
    // 使用了两个哈希表
    // 用来抵消上面最后一个循环
    unordered_map<char, string> hashC;
    unordered_map<string, char> hashS;

    int p = 0;
    for (int i = 0; i < pattern.size(); i++) {
        string tmp = "";

        // 说明字符串中没有word了
        if(p >= str.size())
            return false;
        // 添加下一个word
        while(p < str.size() && str[p] != ' '){
            tmp += str[p];
            p++;
        }
        // 正向和反向判断
        if(hashC.count(pattern[i]) > 0 && hashC[pattern[i]] != tmp)
            return false;
        if(hashS.count(tmp) > 0 && hashS[tmp] != pattern[i])
            return false;
        // 添加
        hashC[pattern[i]] = tmp;
        hashS[tmp] = pattern[i];
        // 准备添加下一个word
        p++;
    }
    // 如果没有word了说明成功
    // 反之失败
    return p >= str.size();
}

int main(int argc, const char *argv[])
{
    cout <<wordPattern("abba", "dog cat cat dog") << endl;;
    return 0;
}
