#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getSum(int a, int b)
{
    int iTempA = a ^ b;
    int iTempB = a & b;
    if(iTempB != 0)
    {
        return getSum(iTempB << 1, iTempA);
    }
    else
    {
        return a | b;
    }
}


int main(int argc, const char *argv[])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "i: " << i << " j: " << j << " sum: " << getSum(i, j) << endl;
        }
    }
    return 0;
}
