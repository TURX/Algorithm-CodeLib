// not ac
#include <iostream>
using namespace std;

int xa, xb, ya, yb, xc, xd, yc, yd;

int main() {
    ios::sync_with_stdio(false);
    cin >> xa >> ya >> xb >> yb;
    if(xa != xb && ya != yb) {
        xc = xa + 1; yc = yb + abs(yb - ya) + 1; xd = xa - abs(xb - xa) + 1; yd = yb + 1;
    } else {
        if(xa == xb) {
            int tx = xa - abs(yb - ya);
            xc = tx; yc = yb; xd = tx; yd = ya;
        } else {
            int ty = ya - abs(yb - ya);
            xc = xb; yc = ty; xd = xa; yd = ty;
        }
    }
    cout << xc << " " << yc << " " << xd << " " << yd << endl;
    return 0;
}