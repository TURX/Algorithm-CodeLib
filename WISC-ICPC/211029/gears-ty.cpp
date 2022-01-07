#include <iostream>
using namespace std;

void exgcd(long long a, long long b, long long &d, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        d = b;
    } else {
        long long tx, ty;
        exgcd(b % a, a, d, tx, ty);
        x = ty - (b / a) * tx;
        y = tx;
    }
}

int main() {
#ifdef VSCODE_DBG
    freopen("test.in", "r", stdin);
#endif
    long long a, b, d, x, y, b1, b2, m1, m2, A, B, K;
    int n, cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        bool u = true;
        cin >> m1 >> b1;
        for (int i = 2; i <= n; i++)
        {
            cin >> m2 >> b2;
            A = m1;
            B = m2;
            K = b2 - b1;
            exgcd(A, B, d, x, y);
            if (K % d != 0)
                u = false;
            x = ((x * (K / d) % (B / d)) + (B / d)) % (B / d);
            b1 = x * m1 + b1;
            m1 = m1 * m2 / d;
        }
        if (u == false)
            cout << "Impossible" << endl;
        else
            cout << b1 << endl;
    }

    return 0;
}