#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int M, N, hajimeX, hajimeY, owariX, owariY;
bool chizu[16][16], visited[16][16], prtflag;
string S; stringstream SS;

inline string delLastEle() {
    if(!S.length()) return S;
    for(int t = S.length() - 1; t >= 0; t--) {
        if(S[t] == '-') return S.substr(0, t);
    }
    S.clear();
    return S;
}

inline void loadS(const int& imaX, const int& imaY) {
    if(!prtflag) {
        S = delLastEle();
        SS << "(" << imaX + 1 << "," << imaY + 1 << ")";
        prtflag = true;
    } else {
        SS << "->(" << imaX + 1 << "," << imaY + 1 << ")";
    }
    S += SS.str();
    SS.clear();
}

void dfs(const int& imaX, const int& imaY) {
    if(imaX == owariX - 1, imaY == owariY - 1) {
        loadS(imaX, imaY);
        cout << S << endl;
        return;
    }
    if(visited[imaX][imaY]) return;
    visited[imaX][imaY] = true;
    loadS(imaX, imaY);
    if(imaX > 1) if(chizu[imaX - 1][imaY]) dfs(imaX - 1, imaY);
    if(imaY < N) if(chizu[imaX][imaY + 1]) dfs(imaX, imaY + 1);
    if(imaX < M) if(chizu[imaX + 1][imaY]) dfs(imaX + 1, imaY);
    if(imaY > 1) if(chizu[imaX][imaY - 1]) dfs(imaX, imaY - 1);
    prtflag = false;
    visited[imaX][imaY] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N;
    for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) cin >> chizu[i][j];
    cin >> hajimeX >> hajimeY >> owariX >> owariY;
    dfs(hajimeX - 1, hajimeY - 1);
    return 0;
}