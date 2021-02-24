#include <iostream>
using namespace std;

int N, A[101], avg = 0, step = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int t = 0; t < N; t++) {
        cin >> A[t];
        avg += A[t];
    }
    avg /= N;
    for (int t = 0; t < N; t++) {
        if (A[t] - avg) {
            A[t + 1] += A[t] - avg;
            step++;
        }
    }
    cout << step << endl;
    return 0;
}