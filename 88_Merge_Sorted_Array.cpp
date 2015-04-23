#include <iostream>
#include <string>
using namespace std;

void merge(int A[], int m, int B[], int n){
    if(n == 0)
        return;
    int sum = n+m-1;
    m--,n--;
    while(n != -1 && m != -1){
        if(A[m] > B[n])
            A[sum--] = A[m--];
        else
            A[sum--] = B[n--];
    }
    
    while(m != -1)
        A[sum--] = A[m--];

    while(n != -1)
        A[sum--] = B[n--];
    return;
}

int main(int argc, const char *argv[])
{
    int A[] = {1, 3, 5, 7};
    int d[] = {0, 0, 0, 0};//这里加这个数组的原因就是为了让A后面有足够的空间
    int B[] = {2, 4, 6, 8};
    int* C = A;
    merge(A, 4, B, 4);
    int i = 0;
    while(i < 8){
        cout << *C << " ";
        C++;
        i++;
    }
    cout << endl;
    return 0;
}
