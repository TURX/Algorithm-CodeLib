#include <iostream>
using namespace std;

int A[100], B[100];
int N, m, SSwaps, SComparison;
string S;
char t;

int selectionSort() {
	for (int i = 0; i < N; i++) {
		m = i;

		for (int j = i + 1; j < N; j++) {
			SComparison++;

			if (A[j] < A[m]) {
				m = j;
				SSwaps++;
			}
		}


		int temp2 = A[i];
		A[i] = A[m];
		A[m] = temp2;
	}
	return SSwaps;
}

int insertionSort() {
	int current, i, j, count = 0;
	for (i = 1; i < N; i++) {
		current = A[i];
		for (j = i - 1; j >= 0; j--) {
			if (current < A[j]) {
				A[j + 1] = A[j];
				count++;
			}
			else
				break;
		}
		A[j + 1] = current;
	}
	return count;
}

int main() {
	cin >> S;
	N = S.length();
	for (int i = 0; i < N; i++) {
		A[i] = S[i] - 'A' + 1;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] == 1)
			N--;
		else
			break;
	}
	cout << selectionSort() << endl;
	return 0;
}
