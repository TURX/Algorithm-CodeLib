#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 可以考虑字典树

int a, b, c, d;
unsigned long long ans;

struct Trie {
    int son[5];
    char val;
} T[2003], SampleT;

struct TrieUtil {
    int trieCounter;
    bool visited[2003];
    inline int insertChar(const char& ch, const int& father) {
        trieCounter++;
        T[trieCounter].val = ch - '0';
        T[father].son[ch - '0'] = trieCounter;
        return trieCounter;
    }
    inline void insertString(const string& str) {
        int current = 0;
        for(int t = 0; t < str.length(); t++) {
            if(!T[current].son[str[t] - '0']) {
                current = insertChar(str[t], current);
            }
            else {
                current = T[current].son[str[t] - '0'];
            }
        }
    }
    inline bool queryString(string& str, const int& start, int current) {
        if(start == str.length()) return false;
        for(int t = start; t < str.length(); t++) {
            if(T[current].son[str[t] - '0']) {
                current = T[current].son[str[t] - '0'];
            } else {
                if(!visited[current]) {
                    visited[current] = true;
                }
            }
        }
    }
    /*
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
    */
} U;

void SearchT(const string& u, string str, const int& c, const int& d, int currentC, int currentD, const bool& work) {
    if(currentC > c && currentD > d) {
        if(U.queryString(str, 0, 0)) ans++;
        return;
    }
    str.push_back(work + '0');
    if(work) currentD++; else currentC++;
}

void SearchU(string str, const int& a, const int& b, int currentA, int currentB, const bool& work) {
    if(currentA == a && currentB == b) {
        for(int t = 0; t < a + b; t++) {
            T[t] = SampleT;
        } // Initialization
        U.insertString(str);
        return;
    }
    str.push_back(0 + '0');
    if(work) currentB++; else currentA++;
    if(currentA < a) SearchU(str, a, b, currentA, currentB, 0);
    if(currentB < b) SearchU(str, a, b, currentA, currentB, 1);
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    SearchU("", a, b, 0, 0, 0);
    SearchU("", a, b, 0, 0, 1);
    cout << ans << endl;
    return 0;
}