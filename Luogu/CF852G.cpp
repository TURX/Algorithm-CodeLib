#define MAXL 1001
#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

bool visited[MAXL];

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
        T[current].counter++;
    }
    inline int queryString(string& str, const int& start, int current) {
        if(start == str.length() - 1)
        int ans = 0;
        for(int t = start; t < str.length(); t++) {
            if(str[t] != '?') {
                if(T[current].son[str[t] - 'a']) {
                    current = T[current].son[str[t] - 'a'];
                } else {
                    if(!visited[current]) {
                        ans += T[current].counter;
                        visited[current] = true;
                    }
                }
            } else {
                for(char ch = 'a'; ch <= 'e'; ch++) {
                    str[t] = ch;
                    ans += queryString(str, t, current);
                }
                ans += queryString(str, t + 1, current);
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
        memset(visited, 0, sizeof(visited));
        cout << U.queryString(tmpStr, 0, 0) << endl;
    }
    return 0;
}