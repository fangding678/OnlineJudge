//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C1_1_H
#define ONLINEJUDGE__C1_1_H

class Different {
public:
    bool checkDifferent(string iniString) {
        if (iniString.size() > 256) {
            return false;
        }
        bool flag[256] = {false};
        for (auto c : iniString) {
            int ind = c;
            if (flag[ind]) {
                return false;
            }
            flag[ind] = true;
        }
        return true;
    }
};

void func() {
    cout << "running begin..." << endl;
    Different different;
    cout << different.checkDifferent("sagdfhj") << endl;
    cout << "running end..." << endl;
}

#endif //ONLINEJUDGE__C1_1_H
