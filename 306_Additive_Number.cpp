#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 字符串的加法
string addString(string& s1, string& s2){
    int s1Index = s1.size()-1;
    int s2Index = s2.size()-1;
    int temp = 0;
    int carrier = 0;
    string res;
    while(s1Index >= 0 && s2Index >= 0){
        temp = s1[s1Index] - '0' + s2[s2Index] - '0' + carrier;
        res = (char)(temp%10+'0') + res;
        carrier = temp>9;
        s1Index--;
        s2Index--;
    }
    if(s1Index >= 0){
        while(s1Index >= 0){
            temp = s1[s1Index] - '0' + carrier;
            res = (char)(temp%10+'0') + res;
            carrier = temp>9;
            s1Index--;
        }
    }else if(s2Index >= 0){
        while(s2Index >= 0){
            temp = s2[s2Index] - '0' + carrier;
            res = (char)(temp%10+'0') + res;
            carrier = temp>9;
            s2Index--;
        }
    }
    return carrier > 0 ? '1'+res : res;
}

bool isAdditiveNumber(string num){
    int curIndex, len = num.size();
    // 从开始的两个数开始加起，看是否能到最后
    for (int i = 1; i < num.size(); i++) {
        for (int j = i+1; j < num.size(); j++) {
            string first = num.substr(0, i);
            string second = num.substr(i, j-i);
            if((first.size() > 1 && first[0] == '0')
             || (second.size() > 1 && second[0] == '0'))
                continue;
            string sum = addString(first, second);
            curIndex = j;
            while(curIndex < len 
               && sum == num.substr(curIndex, sum.size())){
                curIndex += sum.size();
                string temp = sum;
                //first = sum;
                sum = addString(sum, second);
                //second = first;
                first = second;
                second = temp;
                // 这里注释里的代码也是正确的
                // 把first当做temp
                // second当做first
                // sum当做second
            }
            if(curIndex == len){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char *argv[])
{
    cout << isAdditiveNumber("112358") << endl;
    cout << isAdditiveNumber("199100199") << endl;
    cout << isAdditiveNumber("1203") << endl;
    return 0;
}
