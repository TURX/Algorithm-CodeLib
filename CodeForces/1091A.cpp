#include <iostream>
using namespace std;

int y, b, r, minOfAll, current;

inline bool checkValid(const int& start) {
    return (y >= start && b >= start + 1 && r >= start + 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> y >> b >> r;
    minOfAll = min(y, min(b, r));
    if(minOfAll == y) {
        current = y;
        while(!checkValid(current)) current--;
        cout << 3 * current + 3 << endl;
        return 0;
    }
    if(minOfAll == b) {
        current = b;
        while(!checkValid(current - 1)) current--;
        cout << 3 * current << endl;
        return 0;
    }
    if(minOfAll == r) {
        current = r;
        while(!checkValid(current - 2)) current--;
        cout << 3 * current - 3 << endl;
        return 0;
    }
    return 0;
}