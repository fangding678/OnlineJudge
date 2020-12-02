//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C212_H
#define ONLINEJUDGE__C212_H
#include <iostream>
#include <string>
#include <vector>
#include "../_utils/_debug.h"

using namespace std;

class Solution {
public:
    vector<string> ans;
    bool findWord(vector<vector<char>> &board, string &word) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                findWordHelper(board, word, i, j);
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        for (auto word : words) {
            if (findWord(board, word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

void func() {
//    board = [["o","a","a","n"],['e','t','a','e'],[],[]]
//    words = []
    vector<vector<char>> board;
    vector<char> v1{'o','a','a','n'};
    vector<char> v2{'e','t','a','e'};
    vector<char> v3{'i','h','k','r'};
    vector<char> v4{'i','f','l','v'};
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);
    vector<string> words{"oath","pea","eat","rain"};
    string flag_start = "start...";
    cout << flag_start << endl;
    Solution solution;
    _print(solution.findWords(board, words));
    string flag_end = "end...";
    cout << flag_end << endl;
}

#endif //ONLINEJUDGE__C212_H
