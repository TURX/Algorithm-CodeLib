#include <iostream>
using namespace std;

int a[] = {5, 4, 3, 2, 1};
int size = 5;

void insertionSort() {
	for (int i = 0; i < size; i++) {
		int temp = a[i];
		int last = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > temp) {
				a[j + 1] = a[j];
			} else {
				last = j;
				break;
			}
		}
		a[last] = temp;
	}
}

int main() {
	insertionSort();
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
