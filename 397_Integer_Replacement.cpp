#include <iostream>
#include <string>
#include <vector>

using namespace std;

int helper(long n)
{
    if(n <= 1)
    {
        return 0;
    }

    if(n & 1)
    {
        return 1 + min(helper(n-1), helper(n+1));
    }
    else
    {
        return 1 + helper(n/2);
    }
}

int integerReplacement(int n)
{
    return helper(n);
}

int main(int argc, char const* argv[])
{
    cout << integerReplacement(7) << endl;
    return 0;
}
