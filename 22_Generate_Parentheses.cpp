#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addPare(vector<string> &res, string str, int n, int flag){
    if(n==0 && flag==0){
        res.push_back(str);
        return;
    }
    if(flag > 0)
        addPare(res, str+")", n, flag-1);
    if(n > 0)
        addPare(res, str+"(", n-1, flag+1);
}

vector<string> generateParenthesis(int n){
    if(n == 0)
        return vector<string>(1,"");
    vector<string> res;
    if(n == 1)
        return vector<string>(1,"()");
    addPare(res, "", n, 0);
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> res = generateParenthesis(3);
    for(vector<string>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
