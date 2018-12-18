#include <iostream>
using namespace std;

int n, m, c, d, a[15000][15000], tot;
/* Description
 * n: continuously scouting for n times
 * m: the total time for single scouting
 * c: the cards' number of a continuously scouting
 * d: the maxmium time for continuously single scouting
 * Total cards: c * n + m
 */

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> c >> d;
    tot = c * n + m;
    for(int i = 1; i <= tot; i++) {
        cin >> a[i][0];
    }
    for(int i = 1; i <= tot; i++) {
        int n = 0;
        a[i] = max(a[i][j - 1], a[i][j - 1] * c);
    }
    return 0;
}