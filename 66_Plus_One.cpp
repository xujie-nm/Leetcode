#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits){
    for (int i = digits.size() - 1; i >= 0; i--) {
        if(++digits[i] == 10){
            digits[i] = 0;
        }else
            break;
    }
    if(digits[0] == 0)
        digits.insert(digits.begin(), 1);

    return digits;
}

int main(int argc, const char *argv[])
{
    vector<int> dd;
    dd.push_back(9);
    dd.push_back(9);
    dd.push_back(9);
    
    vector<int> res;
    res = plusOne(dd);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
