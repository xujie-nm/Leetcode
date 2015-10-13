#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canWinNim(int n){
    return n%4;
}

int main(int argc, const char *argv[])
{
    cout << canWinNim(1) << endl;
    cout << canWinNim(2) << endl;
    cout << canWinNim(3) << endl;
    cout << canWinNim(4) << endl;
    cout << canWinNim(5) << endl;
    cout << canWinNim(6) << endl;
    cout << canWinNim(7) << endl;
    return 0;
}
