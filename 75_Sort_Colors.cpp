#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sortColors(int A[], int n){
    if(n <= 1)
        return;
    int i = 0;
    int state = 0;
    while(i < n){
        if(A[i] == state){
           i++;
           continue;
        }
        int j = i+1;
        while(j < n){
            if(A[j] == state){
                swap(A[i], A[j]);
                break;
            }
            j++;
        }
        if(j == n)
            state++;
        if(state == 3)
            break;
    }
}

int main(int argc, const char *argv[])
{
    int A[] = {0, 0, 2, 2, 0, 0, 0, 1, 1, 1, 2, 1, 0};
    sortColors(A, 13);

    for (int i = 0; i < 13; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
