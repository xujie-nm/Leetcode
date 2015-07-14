#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int compareVersion(string version1, string version2){
    int first = 0, second = 0;
    int pos1, pos2;
    if(version1 == "0" && version2 == "0")
        return 0;
    
    if((pos1 = version1.find('.')) != string::npos){
        first = atoi(version1.substr(0, pos1).c_str());
        version1 = version1.substr(pos1+1);
    }else{
        first = atoi(version1.c_str());
        version1 = "0";
    }

    if((pos2 = version2.find('.')) != string::npos){
        second = atoi(version2.substr(0, pos2).c_str());
        version2 = version2.substr(pos2+1);
    }else{
        second = atoi(version2.c_str());
        version2 = "0";
    }

    if(first > second)
        return 1;
    else if(first < second)
        return -1;
    else
        return compareVersion(version1, version2);
}
   
   
int main(int argc, const char *argv[])
{
    cout << compareVersion("0.1", "1.1") << endl;
    cout << compareVersion("13.37", "1.2") << endl;
    cout << compareVersion("0", "1") << endl;
    cout << compareVersion("0.333333", "0.333333") << endl;
    return 0;
}
