#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if(nRows <= 1)
                return s;
            string substrings[nRows];
            int row = 0;
            bool down = true;
            for(int i = 0; i < s.size(); i++)
            {
                substrings[row].push_back(s[i]);
                if(down)
                {
                    if(row == nRows-1)
                    {
                        down = false;
                        row--;
                    }
                    else
                        row++;
                }
                else
                {
                    if(row == 0)
                    {
                        down = true;
                        row++;
                    }
                    else
                        row--;
                }
            }
            s = "";
            for (int i = 0; i < nRows; i++)
            {
                s += substrings[i];
            }
           return s;
    
       }
};


int main(int argc, const char *argv[])
{
    cout << convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
