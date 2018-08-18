// luogu-judger-enable-o2
#include <iostream>
#include <string>
using namespace std;
bool a;
int n, m, s;
struct Person {
    bool o; // Orientation
    string e; // Name
} p[10003];
int pointer;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int t = n - 1; t >= 0; t--) {
        cin >> p[t].o >> p[t].e;
    }
    pointer = n - 1;
    for(int t = 0; t < m; t++) {
        cin >> a >> s;
        switch(p[pointer % n].o) {
            case 0:
                switch(a) {
                    case 0:
                        pointer += s;
                        break;
                    case 1:
                        pointer -= s;
                        break;
                }
                break;
            case 1:
                switch(a) {
                    case 0:
                        pointer -= s;
                        break;
                    case 1:
                        pointer += s;
                        break;
                }
                break;
        }
    }
    cout << p[pointer % n].e << endl;
    return 0;
}