#include <iostream>
#include <map>
using namespace std;

int GameNum = 1, N, S[1001], G[1001];
map<int, int> T, E, A;

int main() {
    while (cin >> N) {
        if (N == 0) break;
        cout << "Game " << GameNum++ << ":" << endl;
        for (int i = 1; i <= N; i++) cin >> S[i];
        while (true) {
            for (int i = 1; i <= N; i++) cin >> G[i];
            int cntZero = 0, strong = 0, weak = 0;
            for (int i = 1; i <= N; i++) if (G[i] == 0) cntZero++; else break;
            if (cntZero == N) break;
            for (int i = 1; i <= N; i++) {
                if (S[i] == G[i]) strong++;
                T[S[i]]++; E[G[i]]++;
            }
            for (map<int, int>::iterator it = T.begin(); it != T.end(); it++)
                A[it->first] = min(T[it->first], E[it->first]);
            for (map<int, int>::iterator it = T.begin(); it != T.end(); it++)
                A[it->first] = min(T[it->first], E[it->first]);
            for (map<int, int>::iterator it = A.begin(); it != A.end(); it++)
                weak += it->second; // nums appeared in both seqs
            weak -= strong;
            cout << "    (" << strong << "," << weak << ")" << endl;
            T.clear(); E.clear(); A.clear();
        }
    }
    return 0;
}
