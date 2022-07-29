//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;


class Test2 {
public:
    void fun_test1(vector<vector<string>> &input_evc, vector<pair<string, float>>& output_vec) {
        for (auto &vec : input_evc) {
            output_vec.push_back(make_pair(vec[0], std::atof(vec[1].c_str())));
        }
    }
};

void run_func2() {
    Test2 test2;
    vector<vector<string>> input_evc;
    vector<string> t1 = {"index", "0.1"};
    vector<string> t2 = {"search", "0.2"};
    input_evc.push_back(t1);
    input_evc.push_back(t2);
    vector<pair<string, float>> output_vec;
    test2.fun_test1(input_evc, output_vec);
    for (auto &ouput : output_vec) {
        cout << ouput.first << ": " << ouput.second << endl;
    }
}

