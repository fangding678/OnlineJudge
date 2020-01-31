#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> tm;
    vector<string> path;
    bool isWords1Begin;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        ans.clear();
        tm.clear();
        path.clear();
        path.push_back(beginWord);
        if(beginWord == endWord) {
            ans.push_back(path);
            return ans;
        }
        unordered_set<string> words1;
        unordered_set<string> words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        isWords1Begin = false;
        if(findLaddersHelper(words1, words2, wordList)) {
            getPath(beginWord, endWord);
        }
        return ans;
    }
    bool findLaddersHelper(unordered_set<string> &words1, unordered_set<string> &words2,
                           unordered_set<string> &wordList) {
        isWords1Begin = !isWords1Begin;
        if(words1.empty()) {
            return false;
        }
        if(words1.size() > words2.size()) {
            return findLaddersHelper(words2, words1, wordList);
        }
        for(auto it = words1.begin(); it != words1.end(); ++it) {
            wordList.erase(*it);
        }
        for(auto it = words2.begin(); it != words2.end(); ++it) {
            wordList.erase(*it);
        }
        unordered_set<string> words3;
        bool reach = false;
        for(auto it = words1.begin(); it != words1.end(); ++it) {
            string w = *it;
            for(auto ch = w.begin(); ch != w.end(); ++ch) {
                char c = *ch;
                for(*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if(c == *ch) {
                        continue;
                    }
                    if(words2.find(w) != words2.end()) {
                        reach = true;
                        isWords1Begin ? tm[*it].push_back(w) : tm[w].push_back(*it);
                    }
                    else if(!reach && wordList.find(w) != wordList.end()) {
                        words3.insert(w);
                        isWords1Begin ? tm[*it].push_back(w) : tm[w].push_back(*it);
                    }
                }
                *ch = c;
            }
        }
        return reach || findLaddersHelper(words2, words3, wordList);
    }
    void getPath(string &beginWord, string &endWord) {
        if(isCheck(beginWord, endWord)) {
            path.push_back(endWord);
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        for(auto it = tm[beginWord].begin(); it != tm[beginWord].end(); ++it) {
            path.push_back(*it);
            getPath(*it, endWord);
            path.pop_back();
        }
    }
    bool isCheck(const string &s1, const string &s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        int n = 0;
        for(size_t i=0; i<s1.size(); ++i) {
            if(s1[i] != s2[i]) {
                ++n;
            }
        }
        return n==1;
    }
};

//此方法是单向广度优先遍历，大数据超时
/*
class Solution1 {
private:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> tm;
    vector<string> path;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        ans.clear();
        tm.clear();
        path.clear();
        path.push_back(beginWord);
        if(beginWord == endWord) {
            ans.push_back(path);
            return ans;
        }
        unordered_set<string> words;
        words.insert(beginWord);
        if(findLaddersHelper(words, endWord, wordList)) {
            getPath(beginWord, endWord);
        }
        return ans;
    }
    bool findLaddersHelper(unordered_set<string> &words, string &endWord, unordered_set<string> &wordList) {
        if(words.empty()) {
            return false;
        }
        for(auto it = words.begin(); it != words.end(); ++it) {
            wordList.erase(*it);
            if(isCheck(*it, endWord)) {
                return true;
            }
        }
        unordered_set<string> words1;
        for(auto it = words.begin(); it != words.end(); ++it) {
            string w = *it;
            for(auto iw = wordList.begin(); iw != wordList.end(); ++iw) {
                if(isCheck(w, *iw)) {
                    tm[w].push_back(*iw);
                    words1.insert(*iw);
                }
            }
        }
        return findLaddersHelper(words1, endWord, wordList);
    }
    void getPath(string &beginWord, string &endWord) {
        if(isCheck(beginWord, endWord)) {
            path.push_back(endWord);
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        for(auto it = tm[beginWord].begin(); it != tm[beginWord].end(); ++it) {
            path.push_back(*it);
            getPath(*it, endWord);
            path.pop_back();
        }
    }
    bool isCheck(const string &s1, const string &s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        int n = 0;
        for(size_t i=0; i<s1.size(); ++i) {
            if(s1[i] != s2[i]) {
                ++n;
            }
        }
        return n==1;
    }
};
*/

//此方法过于暴力，超时
/*
class Solution2 {
private:
    vector<vector<string>> ans;
    vector<bool> mark;
    size_t len;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        ans.clear();
        len = INT_MAX;
        int n = wordList.size();
        mark.resize(n);
        fill_n(mark.begin(), n, false);
        deque<string> a;
        a.push_back(beginWord);
        findLadders(beginWord, endWord, wordList, a);
        return ans;
    }
    bool isCheck(const string &s1, const string &s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        int n = 0;
        for(size_t i=0; i<s1.size(); ++i) {
            if(s1[i] != s2[i]) {
                ++n;
            }
        }
        return n==1;
    }
};
*/

int func()
{
    string bs = "qa", es = "sq";
    unordered_set<string> ss;
    string str[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le",
    "av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po",
    "fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb",
    "if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa",
    "pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex",
    "pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    for(string s : str) {
        ss.insert(s);
    }
    Solution S;
    vector<vector<string>> ans = S.findLadders(bs,es, ss);
    for(auto an : ans) {
        for(auto s : an) {
            cout<<s<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
