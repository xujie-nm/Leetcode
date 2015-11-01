#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string getHint(string secret, string guess){
    string res;
    int bulls = 0;
    int cows = 0;
    map<char, int> nums;
    vector<int> tempCows;
    for (int i = 0; i < secret.size(); i++)
        nums[secret[i]]++;
    
    for (int i = 0; i < secret.size(); i++) {
        if(secret[i] == guess[i]){
            bulls++;
            nums[secret[i]]--;
            if(nums[secret[i]] == 0)
                nums.erase(secret[i]);
        }else
            tempCows.push_back(i);
        
    }

    for (int i = 0; i < tempCows.size(); i++) {
        if(nums.count(guess[tempCows[i]]) > 0){
            cows++;
            nums[guess[tempCows[i]]]--;
            if(nums[guess[tempCows[i]]] == 0)
                nums.erase(guess[tempCows[i]]);
        }
    }

    res += to_string(bulls) + "A";
    res += to_string(cows) + "B";
    return res;
}

// faster
// 处理定长时要善用数组hash
string getHint2(string secret, string guess){
    int bulls = 0;
    int cows = 0;
    vector<int> secretVec(10, 0);
    vector<int> guessVec(10, 0);
    // 这两个数组每一位分别存每一个字符串数字出现的次数
    if(secret.size() != guess.size() || secret.empty())
        return "0A0B";

    for (int i = 0; i < secret.size(); i++) {
        char secChar = secret[i], gueChar = guess[i];
        if(secChar == gueChar)
            ++bulls;
        else{
            ++secretVec[secChar-'0'];
            ++guessVec[gueChar-'0'];
        }
    }

    // 这里的两者取最小就是为了防止1234.0111这种情况
    // 0111中只有1在1234中，所以两者取最小可以避免cows增大的情况
    for (int i = 0; i < secretVec.size(); i++) {
        cows += min(secretVec[i], guessVec[i]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main(int argc, const char *argv[])
{
    cout << getHint("1807", "7810") << endl;
    cout << getHint2("1807", "7810") << endl;
    cout << getHint("1", "0") << endl;
    cout << getHint2("1", "0") << endl;
    cout << getHint("1234", "0111") << endl;
    cout << getHint2("1234", "0111") << endl;
    cout << getHint("1122", "1222") << endl;
    cout << getHint2("1122", "1222") << endl;
    return 0;
}
