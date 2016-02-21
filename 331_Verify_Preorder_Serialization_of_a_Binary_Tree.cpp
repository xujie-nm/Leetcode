#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// if null > nonNull+1, this tree is invalid.
// if null < nonNull+1, this tree is incomplete.
// if null = nonNull+1, this tree is complete.
bool isValidSerialization(string preorder){
    if(preorder.empty())
        return false;
    istringstream preorderStream(preorder);
    vector<string> preorderElements;
    string element;
    int counter = 0;

    while(getline(preorderStream, element, ','))
        preorderElements.push_back(element);
    for (int i = 0; i < preorderElements.size()-1; i++) {
        if(preorderElements[i] == "#"){
            if(counter == 0)
                return false;
            else
                --counter;
        }else{
            ++counter;
        }
    }
    return counter != 0 ? false : preorderElements.back() == "#";
}

int main(int argc, const char *argv[])
{
    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << isValidSerialization("9,#") << endl;
    cout << isValidSerialization("9,#,#,1") << endl;
    return 0;
}
