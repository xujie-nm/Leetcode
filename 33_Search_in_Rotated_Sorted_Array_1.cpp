#include <iostream>
using namespace std;

int bin_search(int A[], int begin, int end, int target){
    if(begin > end)
        return -1;
    int mid = (begin + end)/2;
    if(A[mid] == target)
        return mid;
    int res = bin_search(A, begin, mid - 1, target);
    if(res == -1)
        return bin_search(A, mid+1, end, target);
    else
        return res;
}

int search(int A[], int n, int target){
    return bin_search(A, 0, n-1, target);
}

int main(int argc, const char *argv[])
{
    int a[] = {4, 5, 6, 7, 0, 1, 2} ;
    cout << "pos is: " << search(a, 7, 6) << endl;
    return 0;
}
