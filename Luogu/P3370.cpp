#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, A = 1;
string S;
const unsigned long long MAXU = 18446744073709551614UL;
const int P = 233317;
vector<unsigned long long> V;

inline unsigned long long getHash(const string s) {
    int len = s.length();
    unsigned long long ans = 0;
    for(int t = 0; t < len; t++) {
        ans = (ans * len + s[t]) % MAXU + P;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    while(N--) {
        cin >> S;
        V.push_back(getHash(S));
    }
    sort(V.begin(), V.end());
    for(int t = 0; t < V.size() - 1; t++) {
        if(V[t] != V[t + 1]) A++;
    }
    cout << A << endl;
}