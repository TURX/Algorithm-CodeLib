#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;
int n, op, x;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--) {
        cin >> op;
        switch(op) {
            case 1:
                cin >> x;
                Q.push(x);
                break;
            case 2:
                cout << Q.top() << endl;
                break;
            case 3:
                Q.pop();
                break;
        }
    }
    return 0;
}