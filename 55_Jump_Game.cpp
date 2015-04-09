#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canJump(int A[], int n){
    if(n==1)
        return true;
    for (int i = 0; i < n; i++) {
        if(A[i] == 0){
            bool flag = false;
            for (int j = 0; j < i; j++) {
                if(A[j] + j == n-1)
                    return true;
                if(A[j] + j > i)
                  flag = true;
            }
            if(!flag)
                return false;
        }
    }
    return true;
}


int main(int argc, const char *argv[])
{
    int A[] = {2, 0, 0};
    cout << canJump(A, 3) << endl;
    return 0;
}
