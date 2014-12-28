#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0)
                return false;
            int x_1 = x;                                       
            int reverse_x = 0;
            while(x != 0)
            {   
                reverse_x *= 10; 
                reverse_x += x%10;
                x /= 10; 
            }   
            return(x_1 == reverse_x);
        }
};

int main(int argc, const char *argv[])
{
    return 0;
}
