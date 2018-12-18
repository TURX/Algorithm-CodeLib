#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 10000;
int n, opt, k, Queue[MAXN], head, tail;

inline void push(const int& key) {
    tail++;
    Queue[tail] = key;
}

inline void pop() {
    head++;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--) {
        cin >> opt;
        if(opt == 1) {
            cin >> k;
            push(k);
        }
    }
}