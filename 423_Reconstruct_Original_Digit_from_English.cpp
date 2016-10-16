#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Analysis:
// only zero has character 'z'
// only two has character 'w'
// only four has character 'four'
// only six has character 'x'
// only eight has character 'g'
// so:
//  z: zero
//  w: two
//  u: four
//  x: six
//  g: eight
// and
//  h: eight, three         8->3
//  s: six, seven           6->7
//  v: five, seven          7->5
//  o: zero, one, two, four 0,2,4->1
//  n: one, nine, seven     1,7->9

string originalDigits(string s)
{
    vector<int> resNum(10, 0);
    vector<int> cache(26, 0);

    for (int i = 0; i < s.size(); i++) {
        cache[s[i]-'a']++;
    }

    resNum[0] = cache['z'-'a'];
    resNum[2] = cache['w'-'a'];
    resNum[4] = cache['u'-'a'];
    resNum[6] = cache['x'-'a'];
    resNum[8] = cache['g'-'a'];
    resNum[3] = cache['h'-'a'] - resNum[8];
    resNum[7] = cache['s'-'a'] - resNum[6];
    resNum[5] = cache['v'-'a'] - resNum[7];
    resNum[1] = cache['o'-'a'] - resNum[0] - resNum[2] - resNum[4];
    resNum[9] = (cache['n'-'a'] - resNum[1] - resNum[7])/2;
    
    string ret = "";
    for (int i = 0; i < resNum.size(); i++) {
        if(resNum[i] > 0)
        {
            ret += string(resNum[i], i+'0');
        }
    }

    return ret;
}

int main(int argc, const char *argv[])
{
    cout << originalDigits("owoztneoer") << endl;
    return 0;
}
