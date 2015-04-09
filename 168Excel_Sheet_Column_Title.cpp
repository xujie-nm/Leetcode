#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    string convertToTitle(int n) {
        vector<string> result;
        string res;
        while(n > 0)
        { 
            char a;
            if(n % 26 != 0){
                a = 64 + (n % 26);
                n = n / 26;
            }
            else{
                a = 'Z';
                n = n-1;
                n = n / 26;
            }
                result.push_back(string(1,a));
        }
        for(vector<string>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it){
                 res += *it;
        }
        return res;
   }

};


int main(int argc, const char *argv[])
{
    cout << convertToTitle(26) << endl;;
    cout << convertToTitle(25) << endl;;
    cout << convertToTitle(28) << endl;;
    cout << convertToTitle(52) << endl;;
    cout << convertToTitle(100000) << endl;;
    return 0;
}
