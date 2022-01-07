#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 5000001

int arr[MAXN], tmp[MAXN], len;
long long cnt = 0;

// 逆序对
void merge(int l, int mid, int r) {
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
		if (j > r || i <= mid && arr[i] < arr[j]) tmp[k] = arr[i++];
		else tmp[k] = arr[j++], cnt += mid - i + 1;
	for (int k = l; k <= r; k++) arr[k] = tmp[k];
}

void merge2(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge2(l, mid);
	merge2(mid + 1, r);
	int pl = l, pr = mid + 1;
	for (int i = l; i <= r; i++) {
		if (pl <= mid && (pr > r || arr[pr] >= arr[pl])) tmp[i] = arr[pl++];
		else tmp[i] = arr[pr++], cnt += mid - pl + 1;
	}
	for (int i = 1; i <= r; i++) arr[i] = tmp[i];
}

int main() {
	while (cin >> len) {
		memset(arr, 0, sizeof(arr));
		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= len; i++) cin >> arr[i];
		merge(1, len / 2, len);
		cout << cnt << endl;
	}
	return 0;
}
