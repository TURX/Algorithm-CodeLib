#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

unsigned long long N, Len, A[100000];
__gnu_pbds::priority_queue<unsigned long long, less<unsigned long long>, pairing_heap_tag> Q;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> Len;
    for(unsigned long long t = 0; t < N; t++) {
        cin >> A[t];
        Q.push(A)
    }
    return 0;
}