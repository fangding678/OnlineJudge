#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0)
            return 0;
        if(m == 0)
            return -1;
        for(int i=0; i<=m-n; ++i) {
            if(needle == haystack.substr(i, n))
                return i;
        }
        return -1;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}

class SolutionKMP {
public:
    vector<int> KMPpreprocessing(char *s) {
        int n = strlen(s);
        vector<int> match(n,-1);
        int j = -1;
        for(int i=1; i<n; i++) {
            while(j>=0 && s[i]!=s[j+1]) j = match[j];
            if(s[i]==s[j+1]) j++;
            match[i] = j;
        }
        return match;
    }


    int strStr(char *haystack, char *needle) {
        if(!*needle) return 0;
        if(!*haystack) return -1;
        int m = strlen(haystack), n = strlen(needle);
        vector<int> match = KMPpreprocessing(needle);
        int j = -1;
        for(int i=0; i<m; i++) {
            while(j>=0 && haystack[i]!=needle[j+1]) j = match[j];
            if(haystack[i]==needle[j+1]) j++;
            if(j==n-1) return (i-n+1);
        }
        return -1;

    }
};
