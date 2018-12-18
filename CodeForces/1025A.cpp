%:pragma GCC optimize(2)
#include <iostream>
#include <string>
using namespace std;

int N, cntA[26];
string puppies;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> puppies;
    if(N == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    for(int t = 0; t < N; t++) {
        cntA[puppies[t] - 'a']++;
        if(cntA[puppies[t] - 'a'] >= 2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}