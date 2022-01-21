//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

enum AdType{
    APP,
    APP_AD,
    GAME,
    GAME_AD,
    GAME_NEW,
    AD_MOCK,
    AD_NEW,
};

class Test {
public:
    vector<int> fun_test1(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int64_t> ans;
        vector<int> ans1;

        std::int64_t game_s64 = static_cast<std::int64_t>(AdType::GAME);
        int32_t game_32 = static_cast<int32_t>(game_s64);
        std::int32_t game2_32 = static_cast<std::int32_t>(AdType::GAME);
        ans.push_back(game_s64);

        cout << "AdType::GAME = " << AdType::GAME << endl;
        cout << "static_cast<std::int64_t>(AdType::GAME) = " << game_s64 << endl;
        cout << "static_cast<int32_t>(game_s64) = " << game_32 << endl;
        cout << "static_cast<std::int32_t>(AdType::GAME) = " << game2_32 << endl;
        cout << "ans[0] = " << ans[0] << endl;

        string res = "";
        res += std::to_string(game_s64);
        res += std::to_string(game2_32);
        res += AdType::GAME;
        cout << "res = " << res << endl;
        cout << "AdType::GAME = " << AdType::GAME << endl;

        unordered_map<int, set<string>> a;
//        set<string> v1;
//        a[1] = v1;
        a[1].insert("qew");
        for(auto it = a[1].begin(); it != a[1].end(); ++it) {
            cout << *it << endl;
        }
        unordered_map<int, int> cnt_map;
        cnt_map[1]++;
        cnt_map[1]++;
        cout << cnt_map[1] << endl;

        return ans1;
    }
};

void run_func() {
    Test test01;
    vector<int> num1{1, 2};
    vector<int> num2{2, 3};
    auto ans = test01.fun_test1(num1, num2, 1);
    string str = "ads";
    cout << str << endl;
}

