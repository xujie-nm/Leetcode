#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(int n){
    string res;
    res = "1";
    string temp_str;
    if(n >= 2)
    {
        for (int i = 2; i <= n; i++) {
            int count = 0;
            char temp = res[0];
            for (int j = 0; j < res.size(); j++) {
                if(res[j] == temp)
                    count++;
                else{
                    temp_str += char(count + '0');
                    temp_str += res[j-1];
                    count = 1;
                    temp = res[j];
                }
            }
            temp_str += char(count + '0');
            temp_str += res[res.size()-1];
            if(!temp_str.empty())
                res = temp_str;
            temp_str = "";
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    //for (int i = 0; i <5 ; i++) {
        cout << "result: "<<countAndSay(2) << endl;
    //}
    return 0;
}
