#include <iostream>
#include <string>
#include <vector>
using namespace std;

int removeElement(int A[], int length, int elem){
    int i, j;
    int n = length;
    for (i = 0, j = 0; i < length; i++) {
        if(A[i] != elem){
            A[j++] = A[i];
        }else{
            n--;
        }
    }
    return n;
}

int main(int argc, const char *argv[])
{
    int a[] = {3,3};
    int len = removeElement(a, 2, 3);
    cout << "len: " << len << endl;
    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
