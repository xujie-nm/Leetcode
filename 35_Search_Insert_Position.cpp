#include <iostream>
#include <string>
using namespace std;

int searchInsert(int A[], int n, int target){
    int high = n-1;
    int low = 0;
    int mid;
    
    while(high >= low){
        mid = (high + low)/2;
        if(target == A[mid])
            return mid;
        else if(target > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main(int argc, const char *argv[])
{
    int A[] = {1,3,5,6};
    cout << "res: " << searchInsert(A, 4, 0) << endl;
    return 0;
}
