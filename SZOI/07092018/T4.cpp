#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int main() {
    int t;
    for(int i = 0; i < 2; i++) {
        cin >> t;
        a.push_back(t);
    }
    for(int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}