#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10001;

int N, tmpF;

struct Component {
    int a, recv = 0;
    vector<Component*> children;
} C[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int t = 1; t <= N; t++) {
        cin >> C[t].a >> tmpF;
        C[tmpF].children.push_back(&C[t]);
    }
    for (int t = 1; t <= N; t++) {
        for (int i = 0; i < C[t].children.size(); i++) {
            C[t].children[i]
        }
    }
    return 0;
}