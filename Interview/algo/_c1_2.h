//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C1_2_H
#define ONLINEJUDGE__C1_2_H

class Reverse {
public:
    string reverseString(string iniString) {
        int start = 0, end = iniString.size()-1;
        char ct;
        while (start < end) {
            ct = iniString[start];
            iniString[start] = iniString[end];
            iniString[end] = ct;
            ++start;
            --end;
        }
        return iniString;
    }
};

void func() {
    cout << "running begin..." << endl;
    Reverse reverse;
    cout << reverse.reverseString("how are you!") << endl;
    cout << "running end..." << endl;
}

#endif //ONLINEJUDGE__C1_2_H
