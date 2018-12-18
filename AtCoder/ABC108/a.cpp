#include <iostream>
using namespace std;
int K, ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> K;
    for(int i = 1; i <= K; i += 2) {
        for(int j = 2; j <= K; j += 2) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}