%:pragma GCC optimize(2)
#include <iostream>
#include <string>
using namespace std;

bool flag, asterisk;
int N, M;
string S, T;

inline bool queryStr(int ptrA, int ptrB) {
    for(int i = ptrA; i < N;) {
        for(int j = ptrB; j < M;) {
            if(S[i] == '*') {
                if(!asterisk) {
                    if(N - 1 > M) {
                        flag = false;
                        return false;
                    }
                    asterisk = true;
                }
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    S[i] = ch;
                    if(queryStr(i, j)) return true;
                }
                i++;
                for(int k = j; k < M; k++) {
                    if(queryStr(i, k)) return true;
                }
            }
            if(S[i] != T[j]) return false;
            i++; j++;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S >> T;
    flag = queryStr(0, 0);
    switch(flag) {
        case false:
            cout << "NO" << endl;
            break;
        case true:
            cout << "YES" << endl;
            break;
    }
    return 0;
}