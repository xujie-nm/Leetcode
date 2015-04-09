#include <iostream>
#include <string>
#include <vector>
using namespace std;

int jump(int A[], int n){
    if(n==1)
        return 0;
    int locmax;
    int steps = 1;
    int i = 0;
    int j = 1;
    while(i < n-1 && i+A[i] < n-1){
        for (locmax = j; j <= i + A[i]; j++) {
            if( locmax + A[locmax] <= j + A[j])
                locmax = j;
            //找出兩個加起來的最大長度
        }
        i = locmax;
        steps++;
    }
    return  steps;
}
int main(int argc, const char *argv[])
{
    int A[] ={4, 1, 1, 3, 1, 1, 1};
    cout << jump(A, 7) << endl;
    return 0;
}
