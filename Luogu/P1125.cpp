#include<iostream>
#include<string>
#include<algorithm>
#include<memory.h>
using namespace std;
int process[100], sum[100], wait;
string source;
bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) if (n%i == 0) return false;
	return true;
}
bool cmp(int x, int y)
{
	return x > y;
}
int main() {
	memset(process, 0, sizeof(process));
	cin >> source;
	for (int t1 = 0; t1 < source.length(); t1++) {
		for (int t2 = 0; t2 < source.length(); t2++) {
			if (source[t1] == source[t2]) {
				sum[t1]++;
				source[t2] = 1;
			}
		}
		source[t1] = 1;
	}
	sort(sum, sum + source.length(), cmp);
	for (int t1 = 0; t1 < source.length(); t1++) {
		if (sum[t1] != 0) {
			wait = sum[source.length() - 1] - sum[t1];
			if (prime(wait)) cout << "Lucky Word" << endl << wait << endl;
			else cout << "No Answer" << endl << "0" << endl;
		}
	}
}
