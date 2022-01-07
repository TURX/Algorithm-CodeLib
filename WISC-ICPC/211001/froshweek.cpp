#include <iostream>
using namespace std;
#define MAXN 5000001
int arr[MAXN], tmp[MAXN];
long long cnt;

void mergeSort(int L, int R) {
	if (L == R)
		return;
	int mid = (L + R) / 2;
	mergeSort(L, mid);
	mergeSort(mid + 1, R);
	int pL = L, pR = mid + 1;
	for (int i = L; i <= R; i++) {
		if (pL <= mid && (pR > R || arr[pR] >= arr[pL]))
			tmp[i] = arr[pL++];
		else
			tmp[i] = arr[pR++], cnt += mid - pL + 1;
	}
	for (int i = L; i <= R; i++)
		arr[i] = tmp[i];
}

int main() {
	int len;
	while (cin >> len){
		for (int i = 1; i <= len; i++) cin >> arr[i];
		cnt = 0;
		mergeSort(1, len);
		cout << cnt << endl;
	}
    return 0;
}
