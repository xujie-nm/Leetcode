#include <iostream>
#include <string>
#include <stack>
using namespace std;

string getPath(string &path){
    int i = 0;
    string temp = "";
    while(i < path.size() && path[i] != '/'){
        temp += path[i];
        i++;
    }
    if(i >= path.size() - 1)
        path = "";
    else
        path = path.substr(i+1);
    return temp;
}

string simplifyPath(string path){
    string res;
    stack<string> temp;
    while(path != ""){
        string temp_string = getPath(path);
        if(temp_string == ".")
            continue;
        else if(temp_string == ".."){
            if(!temp.empty())
                temp.pop();
        }else if(temp_string != "")
            temp.push(temp_string);
    }
    if(temp.empty())
        return "/";
    else{
        while(!temp.empty()){
            res = "/" + temp.top() + res;;
            temp.pop();
        }
    }
    return res;
}

// no stack
string simplifyPath2(string path){
    string res;
    int size = path.length(), begin(0), len(0);
    for (int i = 0; i <= size; i++) {
        if(!begin && path[i] != '/')
            begin = i;
            // 忽略"//"
        else if(begin && (path[i] == '/' || i == size))
            len = i-begin;
        if(len){
            string temp = path.substr(begin, len);
            begin = len = 0;
            if(!temp.compare("."))
                continue;
                // 跳过"."
            else if(!temp.compare("..")){// 推出一个
                int j = res.length()-1;
                while(res[j] != '/')
                    j--;
                res = res.substr(0, j);
            }else
                res += '/' + temp;
        }
    }
    return res.length() ? res : "/";
}

int main(int argc, const char *argv[])
{ 
    cout << simplifyPath("/.") << endl;
    cout << simplifyPath2("/.") << endl;
    cout << simplifyPath("/..") << endl;
    cout << simplifyPath2("/..") << endl;
    cout << simplifyPath("/...") << endl;
    cout << simplifyPath2("/...") << endl;
    cout << simplifyPath("/....") << endl;
    cout << simplifyPath2("/....") << endl;
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath2("/home/") << endl;
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath2("/a/./b/../../c/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath2("/../") << endl;
    cout << simplifyPath("/home/foo/") << endl;
    cout << simplifyPath2("/home/foo/") << endl;
    return 0;
}
