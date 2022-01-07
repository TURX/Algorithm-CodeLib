#include <iostream>
using namespace std;

int addCnt = 0, multCnt = 0;

int power(int a, int b) {
	int i = 0;
	int y = 1;
	while (i < b) {
		y = y * a; multCnt++;
		i = i + 1;
	}
	return y;
}

int poly1(int c, int a[], int n) {
	int i = 1;
	int y = a[0];
	while (cout << y << " " << i << endl && i <= n) {
		y = y + a[i] * power(c, i); addCnt++; multCnt++;
		i = i + 1;
	}
	return y;
}

int poly2(int c, int a[], int n) {
	int i = 1;
	int y = a[n];
	while (cout << y << " " << i << endl && i <= n) {
		y = y * c + a[n - i]; addCnt++; multCnt++;
		i = i + 1;
	}
	return y;
}

int main() {
	int a[] = {1, 2, 2, 3, 1, 2}; // 1, 2, 2, 3, 1
	int n = 5;
	int c = 3;
	cout << poly1(c, a, n) << endl;
	cout << addCnt << " " << multCnt << endl;
}
