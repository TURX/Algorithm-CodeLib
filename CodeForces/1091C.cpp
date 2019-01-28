%:pragma GCC optimize(3)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned long long> ansList;
unsigned long long N, current, ans;
bool firstFlag;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    ansList.push_back(1);
    for(unsigned long long t = 1; t <= (N >> 1); t++) {
        ans = 0, current = 0, firstFlag = true;
        while(current != 0 || firstFlag) {
            firstFlag = false;
            ans += current + 1;
            current = (current + t) % N;
        }
        ansList.push_back(ans);
    }
    sort(ansList.begin() + 1, ansList.end());
    for(unsigned long long t = 0; t < ansList.size(); t++) {
        if(ansList[t] != ansList[t + 1]) cout << ansList[t] << ' ';
    }
    cout << endl;
    return 0;
}