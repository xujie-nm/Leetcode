#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declaration of guess API
// @para num, you guess
// @return -1 of my number is lower, 1 if my number is higher, otherwise return 0
int guess(int iNum);

int guessNumber(int iN)
{
    int iLow = 1;
    int iHigh = iN;
    int iMid = iLow;
    while(iLow < iHigh)
    {
        iMid = iLow + (iHigh - iLow) / 2;
        if(!guess(iMid))
        {
            return iMid;
        }
        else if(guess(iMid) == 1)
        {
            iHigh = iMid - 1;
        }
        else if(guess(iMid) == -1)
        {
            iLow = iMid + 1;
        }
    }

    return -1;
}
