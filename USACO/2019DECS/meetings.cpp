#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 50001;

int N;
unsigned long long L;

struct Cow {
	unsigned long long x;
	short int d;
	int w;
	friend bool operator <(const Cow& l, const Cow& r) {
		return l.x < r.x;
	}
} cows[MAXN];

int main() {
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	cin >> N >> L;
	for (int i = 0; i < N ; i++)
		cin >> cows[i].w >> cows[i].x >> cows[i].d;
	sort(cows, cows + N);
	for (int i = 0; i < N - 1; i++) {
		if (cows[i].d != cows[i + 1].d) {
			cows[i].d = -cows[i].d;
			cows[i + 1].d = -cows[i].d;
		}
	}
}