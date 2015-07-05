#include <iostream>
#include <string>
#include <vector>
using namespace std;

int titleToNumber(string s){
    if(s.size() == 0)
        return 0;

    int res = 0;
    int count = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        res += (s[i] - 'A' +1) * count;
        count *= 26;
    }
   
    return res;
}

int main(int argc, const char *argv[])
{
    cout << titleToNumber("Z") << endl;
    cout << titleToNumber("AA") << endl;
    cout << titleToNumber("AB") << endl;
    cout << titleToNumber("AC") << endl;


    return 0;
}
