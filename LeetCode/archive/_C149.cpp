#include <iostream>
#include <map>
#include <vector>

using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) {
            return points.size();
        }
        map<pair<int, int>, int> slopes;
        int ans = 0;
        for (int i = 0; i < points.size()-1; ++i) {
            if (ans >= points.size() - i) {
                break;
            }
            slopes.clear();
            int duplicate = 1, t1, t2;
            for (int j = i+1; j < points.size(); ++j) {
                Point a = points[i], b = points[j];
                if (a.x == b.x && a.y == b.y) {
                    duplicate++;
                    continue;
                }
                int g = gcd(a.x-b.x, a.y-b.y);
                slopes[make_pair((a.x-b.x)/g, (a.y-b.y)/g)]++;
            }
            ans = max(ans, duplicate);
            for (auto slope : slopes) {
                if (ans < slope.second + duplicate) {
                    ans = slope.second + duplicate;
                }
            }
        }
        return ans;
    }
    int gcd(int a, int b) {
        int t;
        while (b) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};

