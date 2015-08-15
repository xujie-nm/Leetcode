#include <iostream>
#include <string>
#include <vector>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    int lengthA = C - A;
    int heightA = D - B;
    int lengthB = G - E;
    int heightB = H - F;

    int res = lengthA*heightA + lengthB*heightB;
    
    int commonLength = 0;
    int commonHeight = 0;
    if(A <= E && E <= C){
        if(C < G)
            commonLength = C-E;
        else
            commonLength = G-E;
    }
    if(E <= A && A <= G){
        if(G < C)
            commonLength = G-A;
        else
            commonLength = C-A;
    }

    if(F <= B && B <= H){
        if(H < D)
            commonHeight = H-B;
        else
            commonHeight = D-B;
    }
    if(B <= F && F <= D){
        if(D < H){
            commonHeight = D-F;
        }else
            commonHeight = H-F;
    }

    return res - commonLength*commonHeight;
}

int main(int argc, const char *argv[])
{
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
