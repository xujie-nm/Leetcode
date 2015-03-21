#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int trap(int A[], int n){
    int left = 0; int right = n-1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while(left <= right){
        if(A[left] <= A[right]){
            if(A[left] >= maxleft) 
                maxleft = A[left];
            else
                res += maxleft - A[left];
            left++;
        }
        else{
            if(A[right] >= maxright)
                maxright = A[right];
            else
                res += maxright - A[right];
            right--;
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    int A[] = {5, 4, 3, 2, 1, 2, 3, 4, 5};
    cout << trap(A,9) << endl;;
    return 0;
}
