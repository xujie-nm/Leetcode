#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int strStr(char *haystack, char *needle){
    int len_hay = strlen(haystack);
    int len_nee = strlen(needle);

    if(len_hay < len_nee)
        return -1;
    else if(len_hay == 0 && len_nee == 0)
        return 0;

    for(int i = 0; i <= len_hay - len_nee; i++){
        // if len_hay == len_nee
        int j = 0;
        while(j < len_nee && haystack[i+j] == needle[j]){
            j++;
        }

        if(j == len_nee)
            return i;

    }
    return -1;
}



int main(int argc, const char *argv[])
{
    cout << strStr("a", "a") << endl;
    cout << "ok" << endl;

    return 0;
}
