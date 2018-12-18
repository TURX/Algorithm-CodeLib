#include <iostream>
#include <string>
using namespace std;

int M, N, hajimeX, hajimeY, owariX, owariY;
bool chizu[16][16], visited[16][16], haveflag;// prtflag;

struct Point {
    int x, y;
};

struct StackBox {
    Point stack[103];
    int stackPtr;
    inline void push(const Point& p) {
        stack[stackPtr++] = p;
    }
    inline void pop() {
        stackPtr--;
        if(stackPtr < 0) stackPtr = 0;
    }
    inline Point top() {
        return stack[stackPtr];
    }
    inline int size() {
        return stackPtr;
    }
    inline bool empty() {
        return !stackPtr;
    }
} route;

/*
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
*/

inline void prt() {
    cout << "(" << route.stack[0].x + 1 << "," << route.stack[0].y + 1 << ")";
    for(int t = 1; t < route.size(); t++) {
        cout << "->(" << route.stack[t].x + 1 << "," << route.stack[t].y + 1 << ")";
    }
    cout << endl;
}

void dfs(const int& imaX, const int& imaY) {
    if(!chizu[imaX][imaY] || imaX < 0 || imaY < 0 || imaX >= M || imaY >= N) return;
    if(imaX == owariX - 1 && imaY == owariY - 1) {
        route.push({imaX, imaY});
        haveflag = true;
        prt();
        route.pop();
        return;
    }
    if(visited[imaX][imaY]) return;
    visited[imaX][imaY] = true;
    route.push({imaX, imaY});
    /*
    if(imaY > 1) if(chizu[imaY - 1][imaX]) dfs(imaY - 1, imaX);
    if(imaX < N) if(chizu[imaY][imaX + 1]) dfs(imaY, imaX + 1);
    if(imaY < M) if(chizu[imaY + 1][imaX]) dfs(imaY + 1, imaX);
    if(imaX > 1) if(chizu[imaY][imaX - 1]) dfs(imaY, imaX - 1);
    */
    dfs(imaX, imaY - 1);
    dfs(imaX - 1, imaY);
    dfs(imaX, imaY + 1);
    dfs(imaX + 1, imaY);
    route.pop();
    // prtflag = false;
    visited[imaX][imaY] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N;
    for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) cin >> chizu[i][j];
    cin >> hajimeX >> hajimeY >> owariX >> owariY;
    dfs(hajimeX - 1, hajimeY - 1);
    if(!haveflag) cout << "-1" << endl;
    return 0;
}