#include <iostream>
using namespace std;

int r;

int main() {
    while (cin >> r) {
        if (r == 42) return 0;
        cout << r << endl;
    }
    return 0;
}
