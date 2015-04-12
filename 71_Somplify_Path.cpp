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

int main(int argc, const char *argv[])
{ 
    cout << simplifyPath("/.") << endl;
    cout << simplifyPath("/..") << endl;
    cout << simplifyPath("/...") << endl;
    cout << simplifyPath("/....") << endl;
    cout << simplifyPath("/....") << endl;
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home/foo/") << endl;
    return 0;
}
