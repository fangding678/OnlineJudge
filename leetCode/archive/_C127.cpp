#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int len;
    bool isWords1Begin;
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> words1;
        unordered_set<string> words2;
        if(beginWord == endWord) {
            return 1;
        }
        len = 2;
        words1.insert(beginWord);
        words2.insert(endWord);
        isWords1Begin = false;
        if(!isReach(words1, words2, wordList)) {
            return 0;
        }
        return len;
    }
    bool isReach(unordered_set<string> &words1, unordered_set<string> &words2, unordered_set<string> &wordList) {
        isWords1Begin = !isWords1Begin;
        if(words1.size() == 0) {
            return false;
        }
        if(words1.size() > words2.size()) {
            return isReach(words2, words1, wordList);
        }
        for(auto it = words1.begin(); it != words1.end(); ++it) {
            wordList.erase(*it);
        }
        for(auto it = words2.begin(); it != words2.end(); ++it) {
            wordList.erase(*it);
        }
        unordered_set<string> words3;
        for(auto it = words1.begin(); it != words1.end(); ++it) {
            string w = *it;
            for(auto ch = w.begin(); ch != w.end(); ++ch) {
                char tmp = *ch;
                for(*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if(*ch == tmp) {
                        continue;
                    }
                    if(words2.find(w) != words2.end()) {
                        return true;
                    }
                    if(wordList.find(w) != wordList.end()) {
                        words3.insert(w);
                    }
                }
                *ch = tmp;
            }
        }
        ++len;
        return isReach(words2, words3, wordList);
    }
};

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
    cout<<S.ladderLength(bs,es, ss)<<endl;
    return 0;
}
