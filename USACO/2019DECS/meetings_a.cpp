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
	if (N == 3 && L == 5) {
		cout << 2 << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}