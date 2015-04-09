#include <iostream>
#include <string>
#include <vector>
using namespace std;

string addBinary(string a, string b){
    bool plus = false;
    int n = a.size();
    int m = b.size();
    string res = "";
    while(n > 0 && m > 0){
       if(!plus){
            if(a[n-1] == '1' && b[m-1] == '1'){
                res = '0' + res;
                plus = true;
            }else if((a[n-1] == '0' && b[m-1] == '1') || (a[n-1] == '1' && b[m-1] == '0')){
                res = '1' + res;
                plus = false;
            }else if(a[n-1] == '0' && b[m-1] == '0'){
                res = '0' + res;
                plus = false;
            }
       }else{
            if(a[n-1] == '1' && b[m-1] == '1'){
                res = '1' + res;
                plus = true;
            }else if((a[n-1] == '0' && b[m-1] == '1') || (a[n-1] == '1' && b[m-1] == '0')){
                res = '0' + res;
                plus = true;
            }else if(a[n-1] == '0' && b[m-1] == '0'){
                res = '1' + res;
                plus = false;
            }
       }
       n--;
       m--;
    }
    if(n > 0){
        if(!plus){
            string sub = a.substr(0, n);
            res = sub + res;
        }else{
            while(n > 0){
                if(plus){
                    if(a[n-1] == '1'){
                        plus = true;
                        res = '0' + res;
                    }else{
                        plus = false;
                        res = '1' + res;
                        break;
                    }
                }
                n--;
            }
            if(n>0){
                string sub = a.substr(0, n-1);
                res = sub + res;
            }
            if(plus)
                res = '1' + res;
        }
    }else if(m > 0){
        if(!plus){
            string sub = b.substr(0, m);
            res = sub + res;
        }else{
            while(m > 0){
                if(plus){
                    if(b[m-1] == '1'){
                        plus = true;
                        res = '0' + res;
                    }else{
                        plus = false;
                        res = '1' + res;
                        break;
                    }
                }
                m--;
            }
            if(m>0){
                string sub = b.substr(0, m-1);
                res = sub + res;
            }
            if(plus)
                res = '1' + res;
        }
    }else{
        if(plus)
            res = '1' + res;
    }
    return res;
}

int main(int argc, const char *argv[])
{
    cout << addBinary("11", "1") << endl;

    return 0;
}
