#include <iostream>
using namespace std;

int arr[1000001], len, cnt = 0;

// not efficient, do not use

void bubble_sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				cnt++;
				swap(arr[j], arr[j + 1]);
			}
}

int main() {
	freopen("test.in", "r", stdin);
	cin >> len;
	for (int i = 0; i < len; i++) cin >> arr[i];
	bubble_sort(arr, len);
	cout << cnt << endl;
	return 0;
}
