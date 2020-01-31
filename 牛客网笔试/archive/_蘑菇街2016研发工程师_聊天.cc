#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int q, p, l, r;
    int a[50][2], b[50][2];
//    int c[1000] = {0};
    int total;
    while (cin >> q >> p >> l >> r) {
        total = 0;
        int c[1000] = {0};
        for (int i = 0; i < q; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        for (int i = 0; i < p; i++) {
            cin >> b[i][0] >> b[i][1];
        }
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < q; j++) {
                for (int k = 0; k < p; k++) {
                    if ((b[k][0] + i <= a[j][0] && b[k][1] + i >= a[j][0]) ||
                        (b[k][0] + i <= a[j][1] && b[k][1] + i >= a[j][1]) ||
                        (b[k][0] + i <= a[j][0] && b[k][1] + i >= a[j][1]) ||
                        (b[k][0] + i >= a[j][0] && b[k][1] + i <= a[j][1]))
                        c[i] = 1;
                }
            }
            total += c[i];
        }
        cout << total << endl;
    }

    return 0;
}



/*
A和B是好友，他们经常在空闲时间聊天，A的空闲时间为[a1 ,b1 ],[a2 ,b2 ]..[ap ,bp ]。B的空闲时间是[c1 +t,d1 +t]..[cq +t,dq +t],这里t为B的起床时间。这些时间包括了边界点。B的起床时间为[l,r]的一个时刻。若一个起床时间能使两人在任意时刻聊天，那么这个时间就是合适的，问有多少个合适的起床时间？

输入描述:
第一行数据四个整数：p,q,l,r（1≤p,q≤50,0≤l≤r≤1000)。接下来p行数据每一行有一对整数ai，bi(0≤aii+1>bi,ci+1>di


输出描述:
输出答案个数

输入例子:
2 3 0 20
15 17
23 26
1 4
7 11
15 17

输出例子:
20
*/
