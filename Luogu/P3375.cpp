// luogu-judger-enable-o2
#include <iostream>
#include <cstring>
using namespace std;
char t[1000000], p[1000000];
int pre[1000000];
int tmp;

int main() {
    ios::sync_with_stdio(false);
    cin >> t >> p;
    bool flag = 0; tmp = 0;
    for(int i = 0; i < strlen(t); i++) {
        while(tmp > 0 && p[tmp + 1] != t[i]) tmp = pre[tmp];
        if(p[tmp + 1] == t[i]) tmp++;
        if(tmp == strlen(p)) {
            cout << i - strlen(p) + 1 << endl;
            flag = 1;
        }
    }
    for(int t = 0; t < strlen(p); t++) {
        cout << pre[t] << " ";
    }
    cout << endl;
    return 0;
}