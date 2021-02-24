#include <iostream>
#include <cmath>
using namespace std;

int eprice, equan, price, quan, lprice, lquan, tend, ptr = 0;
int A[100001][2];
double low = -1024576.0, up = 1024576.0;

int main() {
    ios::sync_with_stdio(false);
    cin >> eprice;
    cin >> A[ptr][0] >> A[ptr][1];
    while (true) {
        cin >> price >> quan;
        if (price == -1 && quan == -1) break;
        lprice = A[ptr][0], lquan = A[ptr][1];
        for (int t = lprice + 1; t <= price; t++) {
            ptr++;
            A[ptr][0] = A[ptr - 1][0] + 1; // price++
            A[ptr][1] = A[ptr - 1][1] + (quan - lquan) / (price - lprice); // quan += avgQuan
        }
    }
    cin >> tend;
    if (eprice >= A[ptr][0]) {
        lprice = A[ptr][0];
        for (int t = lprice + 1; t <= eprice + 1; t++) {
            ptr++;
            A[ptr][0] = A[ptr - 1][0] + 1;
            A[ptr][1] = A[ptr - 1][1] - tend;
        }
    }
    for (int t = 0; t <= ptr; t++) {
        if (A[t][0] == eprice) {
            equan = A[t][1];
            break;
        }
    }
    for (int t = 0; t <= ptr; t++) {
        if (equan - A[t][1] > 0) { // equan - quan > 0
            low = max(low, (double)((double)(A[t][0] - A[0][0]) * A[t][1] - (double)(eprice - A[0][1]) * equan) / (double)(equan - A[t][1]));
        } else {
            up = min(up, (double)((double)(A[t][0] - A[0][0]) * A[t][1] - (double)(eprice - A[0][1]) * equan) / (double)(equan - A[t][1]));
        }
    }
    if (low > 0) cout << (int)ceil(low) << endl; else if (up < 0) cout << (int)floor(up) << endl; else cout << 0 << endl;
    return 0;
}