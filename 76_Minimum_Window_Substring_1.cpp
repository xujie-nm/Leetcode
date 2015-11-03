#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

string minWindow(string S, string T){
    string str = "";
    int lenS = S.size();
    int lenT = T.size();
    if(lenT == 0)
        return str;
    int minLen = lenS + 1;
    int num[256], count[256];
    memset(num, 0, sizeof(num));//num数组记录的是字符串T中每个字符出现的次数
    memset(count, 0, sizeof(count));//count数组中记录的是当前S中该字符出现的次数
    for (int index = 0; index <T.size(); index++) {
        num[T[index]]++;
    }

    int first = 0, second = 0;//这两个变量可能是最后结果的开头和结尾
    int chaCount = 0;
    while(second < lenS){
        int secCha = (int)S[second];//取出当前字符
        if(++count[secCha] <= num[secCha]){//出现的次数还不够
            chaCount++;//记录T出现字符的个数
        }
        if(chaCount == lenT){//如果T中的字符全出现了
            while(first <= second){
                int firCha = (int)S[first];//取出最前面的字符
                if(count[firCha] > num[firCha])//说明这个字符不是第一个出现的
                    count[firCha]--, first++;//计数器减一，first后移
                else
                //count[firCha]==num[firCha]，
                //说明这个字符在s中出现的次数等于在t中出现的次数    
                //说明出现了第一个字符
                    break;
            }
            if(minLen > second - first + 1){//如果minLen比这个结果长的话，替换重新区结果
                minLen = second - first + 1;
                str = S.substr(first, minLen);
            }
        }
        second++;
    }
    return str;
}

int main(int argc, const char *argv[])
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("babbBba", "Abbb") << endl;
    return 0;
}
