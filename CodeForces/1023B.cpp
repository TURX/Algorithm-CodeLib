%:pragma GCC optimize(2)
#include <iostream>
using namespace std;

unsigned long long n, k, ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if((n << 1) <= k || k == 1 || k == 2) {
        cout << "0" << endl;
        return 0;
    }
    if(k <= n) {
        cout << ((k - 1) >> 1) << endl;
        return 0;
    }
    if(k > n) {
        cout << (((n - (k - n)) + 1) >> 1) << endl;
        return 0;
    }
    /*
    for(unsigned long long i = 1; i < n; i++) {
        for(unsigned long long j = i + 1; j <= n; j++) {
            if(i + j == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
    */
}