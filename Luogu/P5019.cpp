#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1000003

int glob[MAXN], tag[MAXN], input[MAXN], totalMax, N;

void buildTree(int id, int l, int r) {
	if(l == r) {
		glob[id] = input[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildTree(id << 1, l, mid);
	buildTree(id << 1 | 1, mid + 1, r);
	glob[id] = min(glob[id << 1], glob[id << 1 | 1]);
}

int enquiry(int id, int l, int r, int currentIntervalL, int currentIntervalR) {
	if(l > currentIntervalR || r < currentIntervalL) return INT32_MAX;
    if(l <= currentIntervalL && r >= currentIntervalR) return glob[id];
	int mid = (currentIntervalL + currentIntervalR) >> 1;
	return min(enquiry(id << 1, l, r, currentIntervalL, mid), enquiry(id << 1 | 1, l, r, mid + 1, currentIntervalR));
}

int solve(const int l, const int r, const int peak) {
    if(peak > totalMax) return 0;
    int ans = 0, startMark = l, globMinimum = enquiry(1, l, r, 1, N);
    if(globMinimum == peak) return 0;
    ans += globMinimum - peak;
    for(int t = l; t <= r + 1; t++) {
        if(input[t] <= globMinimum && input[t - 1] > globMinimum) {
            ans += solve(startMark, t - 1, enquiry(1, l, r, 1, N));
        }
        if(input[t] <= globMinimum && input[t + 1] > globMinimum) {
            startMark = t + 1;
        }
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	memset(glob, 0x3f, sizeof(glob));
	cin >> N;
	for(int t = 1; t <= N; t++) {
		cin >> input[t];
		totalMax = max(input[t], totalMax);
	}
	buildTree(1, 1, N);
    cout << solve(1, N, 0) << endl;
	return 0;
}