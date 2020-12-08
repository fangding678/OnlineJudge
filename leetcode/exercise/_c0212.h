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

const int indNum = 26;
const int boardNum = 12;
typedef struct TrieNode {
    TrieNode() {
        for (int i = 0; i < indNum; ++i) {
            p[i] = nullptr;
        }
    }
    string word = "";
    TrieNode* p[indNum];
}TrieNode;

class Solution {
public:
    set<string> ans;
    TrieNode* root;
    int rows;
    int cols;

    void insertWord(string &word) {
        TrieNode *t = root;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            int ind = word[i] - 'a';
            if (nullptr == t->p[ind]) {
                t->p[ind] = new TrieNode();
            }
            t = t->p[ind];
            if (len-1 == i) {
                t->word = word;
            }
        }
    }

    void conTrieDict(vector<string>& words) {
        root = new TrieNode();
        for (auto& word : words) {
            insertWord(word);
        }
    }

    void delTrieDict(TrieNode *t) {
        if (!t) {
            return;
        }
        for (auto & i : t->p) {
            delTrieDict(i);
        }
        delete t;
    }

    void initMask(bool mask[][boardNum]) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mask[i][j] = true;
            }
        }
    }

    void findWord(TrieNode *t, vector<vector<char>> &board, bool mask[][boardNum], int i, int j) {
        int ind = board[i][j] - 'a';
        if (nullptr == t->p[ind]) {
            return ;
        }
        if (t->p[ind]->word != "") {
            ans.insert(t->p[ind]->word);
        }
        mask[i][j] = false;
        if (i < rows-1 && mask[i+1][j]) {
            findWord(t->p[ind], board, mask, i+1, j);
        }
        if (i > 0 && mask[i-1][j]) {
            findWord(t->p[ind], board, mask, i-1, j);
        }
        if (j < cols-1 && mask[i][j+1]) {
            findWord(t->p[ind], board, mask, i, j+1);
        }
        if (j > 0 && mask[i][j-1]) {
            findWord(t->p[ind], board, mask, i, j-1);
        }
        mask[i][j] = true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        vector<string> tans;
        root = new TrieNode();
        rows = board.size();
        if (rows <= 0 || words.empty()) {
            return tans;
        }
        cols = board[0].size();
        conTrieDict(words);
        bool mask[boardNum][boardNum];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                initMask(mask);
                findWord(root, board, mask, i, j);
            }
        }
        delTrieDict(root);
        for (auto &word : words) {
            if (ans.find(word) != ans.end()) {
                tans.push_back(word);
            }
        }
        return tans;
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
