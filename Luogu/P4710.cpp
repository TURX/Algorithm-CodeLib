// 这道题比较凉，算法思路有借鉴
#include <iostream>
#include <cmath>
using namespace std;

double speed, angle;
int main() {
    ios::sync_with_stdio(false);
    cin >> speed >> angle;
    cout << speed * speed * sin(angle) * cos(angle) / (double)10 << " " << speed * speed * cos(angle) * cos(angle) / 2 / (double)10;
}