//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_5_H
#define ONLINEJUDGE__C18_5_H

class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        auto xvec = getIndex(article, x);
        auto yvec = getIndex(article, y);
        int i = 0, j = 0;
        int ans = n;
        while (i < xvec.size() && j < yvec.size()) {
            if (xvec[i] > yvec[j]) {
                ans = min(ans, xvec[i] - yvec[j]);
                ++j;
            } else {
                ans = min(ans, yvec[j] - xvec[i]);
                ++i;
            }
        }
        return ans;
    }

    vector<int> getIndex(vector<string>& article, string &w) {
        vector<int> ivec;
        for (int i = 0; i < article.size(); ++i) {
            if (w == article[i]) {
                ivec.push_back(i);
            }
        }
        return ivec;
    }
};

void func() {
    vector<string> A{"12","11","13","1","2","1","2"};
    Distance distance;
    cout << distance.getDistance(A, 7, "1", "2") << endl;
}

#endif //ONLINEJUDGE__C18_5_H
