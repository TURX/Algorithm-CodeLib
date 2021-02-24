#include <iostream>
#include <map>
#include <string>
#include <bitset>
using namespace std;

const int MAXN = 1007, MAXM = 100007;

map<string, int> D; // word to id mapping
bitset<MAXN> H; // id to bool mapping
int N, M, appe[MAXN], cnt[MAXN];
string S;

inline int count() { // the number of valid cnt[i] in 1 <= i <= N
    int ans = 0;
    for (int i = 1; i <= N; i++) ans += (bool)cnt[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int t = 1; t <= N; t++) {
        cin >> S;
        D[S] = t; // map string S to id t
    }
    cin >> M;
    for (int t = 1; t <= M; t++) {
        cin >> S;
        if (D.count(S)) { // if S exists in D
            appe[t] = D[S]; // original id mapping
            H[D[S]] = true; // appeared
        } else {
            appe[t] = 0; // does not appear
        }
    }

    if (!H.count()) { // nothing matched
        cout << 0 << endl << 0 << endl;
        return 0;
    } else {
        cout << H.count() << endl; // count of matched words
    }

    int l, r = 0;
    appe[0] = 0;
    cnt[0] = 233;
    int len = MAXM;

    while (++r <= M) {
        cnt[appe[r]]++;
        while(!(appe[l] && l < M)) l++;
        while(cnt[appe[l]] > 1) cnt[appe[l++]]--;
        if (count() == H.count()) len = min(len, r - l + 1);
    }

    cout << len << endl;
    return 0;
}