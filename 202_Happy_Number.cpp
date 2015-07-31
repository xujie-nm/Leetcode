#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int getNext(int n){
    int sum = 0;
    
    while( n != 0){
        int temp = n % 10;
        sum += temp * temp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    unordered_map<int, int> hash;
    
    while(n >= 0){
        if(n == 1)
            return true;
        n = getNext(n);
        if(hash[n] == 0)
            hash[n] = 1;
        else
            return false;
    }
    
    return false;
}

int main(int argc, const char *argv[])
{
    cout << "isHappy: " << isHappy(2) << endl;
    return 0;
}
