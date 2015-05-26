#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string s){
    int low = 0;
    int high = s.size() - 1;
    while(low < high){
        if(s[low] > 'Z' && s[low] < 'a' || s[low] > '9' && s[low] < 'A' 
                || s[low] < '0' || s[low] > 'z'){
            low++;
            continue;
        }
        if(s[high] > 'Z' && s[high] < 'a' || s[high] > '9' && s[high] < 'A' 
                || s[high] < '0' || s[high] > 'z'){
            high--;
            continue;
        }
        if(s[low] == s[high] || s[low] - 'A' + 'a' == s[high] ||
           s[low] == s[high] - 'A' + 'a'){
            low++;
            high--;
        }else{
            return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << isPalindrome("race a car") << endl;
    cout << isPalindrome("1a2") << endl;
    cout << isPalindrome("2a2") << endl;
    return 0;
}
