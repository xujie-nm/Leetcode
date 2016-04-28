#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseString(string s){
    if(s.size() <= 1)
        return s;
    int first = 0;
    int second = s.size()-1;
    char temp;
    while(first < second){
        temp = s[first];
        s[first] = s[second];
        s[second] = temp;
        first++;
        second--;
    }
    return s;
}

int main(int argc, const char *argv[])
{
    cout << reverseString("hello") << endl;
    return 0;
}
