#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points){
    if(points.size() < 2)
        return points.size();
    int res = 0;
    for (int i = 0; i < points.size(); i++) {
        Point cur = points[i];
        unordered_map<double, int> hash;
        int ver = 0;
        int localMax = 0;
        int same = 1;
        for (int j = i+1; j < points.size(); j++) {
            Point next = points[j];
            if(cur.x != next.x){
                double slope = (double)(cur.y - next.y)/(double)(cur.x - next.x);
                //calculate slope
                hash[slope]++;
                //find max points on this line
                localMax = max(localMax, hash[slope]);
            }else if(cur.y != next.y){
                //vertical
                ver++;
                localMax = max(localMax, ver);
            }else
                //same points
                same++;
        }
        res = max(res, same + localMax);
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<Point> points;
    points.push_back(Point(1,1));
    points.push_back(Point(2,2));
    points.push_back(Point(1,1));
    points.push_back(Point(3,3));
    points.push_back(Point(4,3));

    cout << maxPoints(points) << endl;
    return 0;
}
