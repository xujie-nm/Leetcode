#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max_index(int A[], int start, int end){
    int max_index = start;
    for (int i = start; i < end; i++) {
        if(A[i] >= A[max_index] ){ 
            max_index = i;
        }
    }
    return max_index;
}

int trap(int A[], int n){
    if(n < 2)
        return 0;
    int sum1  = 0;
    for (int i = 0; i < n; i++) {
        sum1 += A[i];
    }

    int left_max = max_index(A, 0, n);
    int right_max = left_max;
    while(left_max > 0){
        if(left_max - 1>0){
            int temp_left = max_index(A, 0, left_max);
            if(temp_left >= 0){
                for (int i = temp_left; i < left_max; i++) {
                    A[i] = A[temp_left];
                }
                left_max = temp_left;
            }
        }
        else
            break;
    }

    while(right_max < n){
        if(right_max + 1 < n){
            int temp_right = max_index(A, right_max, n);
            if(temp_right < n ){
                for (int i = right_max; i < temp_right; i++) {
                    A[i] = A[temp_right];
                }
                if(temp_right < n - 1)
                    right_max = temp_right + 1;
                else
                    right_max = temp_right;
            }
        }
        else
            break;
    }
   
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += A[i];
        cout << A[i]<< endl;
    }
    return sum2 - sum1;
}

int main(int argc, const char *argv[])
{
    int A[] = {5, 4, 3, 2, 1, 2, 3, 4, 5};
    cout << trap(A,9) << endl;;
    return 0;
}
