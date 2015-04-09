#include <iostream>
#include <string>
#include <vector>
using namespace std;

int removeDuplicates(int A[], int n){
    int length = n, i, j;
    for (i = 1, j = 0; i < n; i++) {
        if(A[j] < A[i]) A[++j] = A[i];
        else
            length--;
    }
    return length;
}

int main(int argc, const char *argv[])
{
    int A[] = {1, 2, 2, 3, 3, 4, 4, 6, 7, 7, 8};
    int re = removeDuplicates(A, 11);
    cout << "re: " << re << endl;
    A = relloc()
    for (int i = 0; i < 11; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
