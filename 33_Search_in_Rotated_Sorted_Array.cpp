#include <iostream>
using namespace std;

int search(int A[], int n, int target){
    if(n == 1){
        if(A[0] == target)
            return 0;
        else
            return -1;
    }
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if(A[i] > A[i+1]){
            pos = i;
            break;
        }
    }
    
    int high, low, mid;
    if(pos != -1){
        if(target > A[0])
        {
            high = pos;
            low = 0;
        }
        else{
            high = n-1;
            low = pos + 1;
        }
    }
    else{
        high = n-1;
        low = 0;
    }

    while(high > low){
        mid = (low + high)/2;
        if(target > A[mid])
            low = mid + 1;
        else if(target < A[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main(int argc, const char *argv[])
{
    int a[] = {1, 3} ;
    cout << "pos is: " << search(a, 2, 1) << endl;
    return 0;
}
