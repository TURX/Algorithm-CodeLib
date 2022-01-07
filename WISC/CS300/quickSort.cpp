#include <iostream>
using namespace std;

int a[100005], size;

void quickSort(int l, int r) {
	if (l >= r) return;
	int p = a[(l + r) / 2]; // pivot
	int i = l, j = r;
	while (i < j) {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i < j) {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	// j: index of last element of low partition
	quickSort(l, j);
	quickSort(j + 1, r);
}

int main() {
	cin >> size;
	for (int i = 0; i < size; i++) cin >> a[i];
	quickSort(0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
