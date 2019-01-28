#define MAXL 1001
#include <iostream>
#include <string>
using namespace std;

struct Trie {
    int son[5];
    int counter;
    char val;
} T[MAXL];

struct TrieUtil {
    int trieCounter;
    inline int insertChar(const char& ch, const int& father) {
        trieCounter++;
        T[trieCounter].val = ch - 'a';
        T[trieCounter].counter++;
        T[father].son[ch - 'a'] = trieCounter;
        return trieCounter;
    }
    inline void insertString(const string& str) {
        int current = 0;
        for(int t = 0; t < str.length(); t++) {
            if(!T[current].son[str[t] - 'a']) {
                current = insertChar(str[t], current);
            }
            else {
                current = T[current].son[str[t] - 'a'];
            }
        }
    }
    inline int queryString(string& str, const int& start, int current) {
        int ans = 0;
        for(int t = start; t < str.length(); t++) {
            if(str[t] != '?') {
                if(T[current].son[str[t] - 'a']) {
                    current = T[current].son[str[t] - 'a'];
                } else {
                    ans += T[current].counter;
                }
            } else {
                for(char ch = 'a'; ch <= 'e'; ch++) {
                    str[t] = ch;
                    ans += queryString(str, t, current);
                }
                if(str[t + 1] != '?') {
                    ans += queryString(str, t + 1, current);
                }
            }
        }
        return ans;
    }
} U;

int N, M;
string tmpStr;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int t = 0; t < N; t++) {
        cin >> tmpStr;
        U.insertString(tmpStr);
    }
    for(int t = 0; t < M; t++) {
        cin >> tmpStr;
        cout << U.queryString(tmpStr, 0, 0) << endl;
    }
    return 0;
}