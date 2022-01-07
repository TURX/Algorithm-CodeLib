#include <iostream>
#include <vector>
using namespace std;

int a[100005], size;

void mergeSort(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergeSort(l, mid); // l - mid sorted
	mergeSort(mid + 1, r); // mid + 1 - r sorted
	// merge
	vector<int> tmp;
	int i = l, j = mid + 1;
	while (i <= mid) {
		while (j <= r) {
			if (a[i] < a[j]) {
				tmp.push_back(a[i]);
				i++;
				if (i > mid) break;
			} else {
				tmp.push_back(a[j]);
				j++;
				if (j > r) break;
			}
		}
		if (j > r) break;
	}
	while (i <= mid) {
		tmp.push_back(a[i]);
		i++;
	}
	while (j <= r) {
		tmp.push_back(a[j]);
		j++;
	}
	for (int t = l; t <= r; t++) {
		a[t] = tmp[t - l];
	}
}

int main() {
	cin >> size;
	for (int i = 0; i < size; i++) cin >> a[i];
	mergeSort(0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
