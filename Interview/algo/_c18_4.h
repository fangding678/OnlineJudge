//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C18_4_H
#define ONLINEJUDGE__C18_4_H

class Count2 {
public:
    int countNumberOf2s(int n) {
        int ans = 0;
        int base = 1;
        int tmp = 1;
        while (n > 0) {
            ans += n / 10 * base;
            if (n % 10 > 2) {
                ans += base;
            } else if (n % 10 == 2) {
                ans += tmp;
            }
            tmp += base * (n % 10);
            n /= 10;
            base *= 10;
        }
        return ans;
    }
};

void func() {
    cout << "running begin..." << endl;
    Count2 count2;
    cout << count2.countNumberOf2s(537) << endl;
    cout << "running end..." << endl;
}

#endif //ONLINEJUDGE__C18_4_H
