#include <iostream>
#include <string>
#include <list>
using namespace std;

int josephuse(int n, int m){
    if(n == 0)
        return -1;
    list<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    auto it = nums.begin();
    int i = 1;
    while(nums.size() > 1){
        if(i < m){
            it++;
            if(it == nums.end())
                it = nums.begin();
            i++;
        }else{
            it = nums.erase(it);
            if(it == nums.end())
                it = nums.begin();
            i = 1;
        }
    }

    return *(nums.begin());
}

/// k+1 ->  0
/// k+2 ->  1
/// ...
/// n-1 -> n-k-2
/// 0   -> n-k-1
/// 1   -> n-k
/// ...
/// k-1 -> n-2
/// 所以最后的递推公式为
///           ->  0                 n=1
/// f(n, m) = |
///           ->  [f(n-1, m)+m]%n   n>1
int josephuse2(int n, int m){
    if(n < 1 || m < 1)
        return -1;

    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res+m) % i;
    }

    return res;
}

int main(int argc, const char *argv[])
{
    int n, m;
    cout << "input: n and m: " << endl;
    while(cin >> n >> m){
        cout << josephuse(n, m) << endl;
        cout << josephuse2(n, m) << endl;
        cout << "input: n and m: " << endl;
    }
    return 0;
}
