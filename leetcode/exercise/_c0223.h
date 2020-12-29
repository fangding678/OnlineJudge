//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool isInArea(int x, int y, int A, int B, int C, int D) {
        if (x >= A && x <= C && y >= B && y <= D) {
            return true;
        }
        return false;
    }

    int calcArea(int A, int B, int C, int D) {
        cout << A << B << C << D << endl;
        return abs((C - A) * (D - B));
    }

    int calcOverLap(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (isInArea(A, B, E, F, G, H)) {
            if (isInArea(C, D, E, F, G, H)) {
                return calcArea(A, B, C, D);
            } else {
                return calcArea(A, B, min(C, G), min(D, H));
            }
        } else if (isInArea(C, B, E, F, G, H)) {
            return calcArea(C, B, E, min(D, H));
        } else if (isInArea(C, D, E, F, G, H)) {
            return calcArea(C, D, max(E, A), F);
        } else if (isInArea(A, D, E, F, G, H)) {
            return calcArea(A, D, G, F);
        } else {
            return 0;
        }
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A) * (D-B);
        int area2 = (G-E) * (H-F);
        int overLapArea1 = calcOverLap(A, B, C, D, E, F, G, H);
        int overLapArea2 = calcOverLap(E, F, G, H, A, B, C, D);
        cout << overLapArea1 << "\t" << overLapArea2 << endl;
        return area1 - max(overLapArea1, overLapArea2) + area2;
    }
};

void func() {
    Solution solution;
//    int a[8] = {-3, 0, 3, 4, 0, -1, 9, 2};
//    int a[8] = {-2, -2, 2, 2, -3, -3, 3, -1};
//    int a[8] = {0, 0, 50000, 40000, 0, 0, 50000, 40000};
    int a[8] = {-5, -2, 5, 1, -3, -3, 3, 3};
    cout << solution.computeArea(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]) << endl;
}

