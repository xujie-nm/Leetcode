#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseVowels(string s){
    if(s.size() <= 1)
        return s;
    vector<int> vowels;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
        || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I'
        || s[i] == 'O' || s[i] == 'U')
            vowels.push_back(i);
    }

    int first = 0;
    int second = vowels.size()-1;

    char temp;
    while(first < second){
        temp = s[vowels[first]];
        s[vowels[first]] = s[vowels[second]];
        s[vowels[second]] = temp;
        first++;
        second--;
    }
    return s;
}

int main(int argc, const char *argv[])
{
    cout << reverseVowels("hello") << endl;
    cout << reverseVowels("leetcode") << endl;
    return 0;
}
