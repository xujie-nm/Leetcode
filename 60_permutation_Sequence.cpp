#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &num) {
    int size = num.size();
    int i , j;
    for (i = size - 2; i >= 0; i--) {
        if(num[i] < num[i + 1]) break;
    }
    if(i >= 0){
        for (j = size - 1; j > i; j--) {
            if(num[j] > num[i]) break;
        }

        int temp = num[i];
        num[i] = num[j];                                                                                        
        num[j] = temp;
    }
    reverse(num.begin() + i + 1, num.end());
}

string getPermutation(int n, int k){
    int sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= i;
    }
    
    if(k > sum)
        return "";

    vector<int> num;
    for (int i = 0; i < n; i++) {
        num.push_back(i+1);
    }

    while(k-1>0){
        nextPermutation(num);
        k--;
    }

    string res = "";
    
    for (int i = 0; i < n; i++) {
        res += num[i] + '0';
    }

    return res;
}

int main(int argc, const char *argv[])
{
    cout << getPermutation(3, 1) << endl;
    cout << getPermutation(3, 2) << endl;
    cout << getPermutation(3, 3) << endl;
    cout << getPermutation(3, 4) << endl;
    cout << getPermutation(3, 5) << endl;
    cout << getPermutation(3, 6) << endl;
    cout << getPermutation(8, 8590) << endl;
    return 0;
}
