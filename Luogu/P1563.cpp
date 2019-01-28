// luogu-judger-enable-o2
#include <iostream>
#include <string>
using namespace std;
bool a;
int n, m, s;
struct Person {
    bool o; // Orientation
    string e; // Name
} p[100003];
long long pointer;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int t = 0; t < n; t++) {
        cin >> p[t].o >> p[t].e;
    }
    for(int t = 0; t < m; t++) {
        cin >> a >> s;
        if(p[pointer % n].o == a) s *= -1;
        pointer += n + s;
    }
    cout << p[pointer % n].e << endl;
    return 0;
}