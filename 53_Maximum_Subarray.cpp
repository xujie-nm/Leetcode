#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxSubArray(int A[], int n){
    int max = A[0];
    int subsum = 0;
    for (int i = 0; i < n; i++) {
        subsum += A[i];
        if(subsum > max)
            max = subsum;
        if(subsum < 0)
            subsum = 0;
    }
    
    return max;
}

int main(int argc, const char *argv[])
{
    int A[] = {1};
    cout << maxSubArray(A, 1) << endl;
    return 0;
}
