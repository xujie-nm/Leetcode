#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int lengthOfLastWord(const char *s){
    int len = strlen(s);
    if(len == 0)
        return 0;
    int res = 0;
    int i = len-1;
    while(s[i] == ' ')
        i--;
    while(i >= 0){
        if(s[i] == ' ')
            return res;
        i--;
        res++;
    }
    return res;
}


int main(int argc, const char *argv[])
{
    char s[] = "      ";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
