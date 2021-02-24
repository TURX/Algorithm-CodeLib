#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 2500;

int C, L;
pair<int, int> CA[MAXN], LA[MAXN];

inline bool comp(const array<int, 2>& l, const array<int, 2>& r) {
    return l[0] < r[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> C >> L;
    for (int t = 0; t < C; t++) cin >> CA[t][0] >> CA[t][1];
    for (int t = 0; t < L; t++) cin >> LA[t][0] >> LA[t][1];
    sort(CA, CA + C, comp);
    for (int t = 0; t < C; t++) cout << CA[t][0] << " " << CA[t][1] << endl;
    return 0;
}