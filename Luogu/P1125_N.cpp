#include<iostream>
#include<cstring>
#include<algorithm>
#include<memory.h>
using namespace std;
int process[10001], sum[10001], wait;
char source[10001];
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
	int len = strlen(source);
	memset(process, 0, sizeof(process));
	cin >> source;
	for (int t1 = 0; t1 < len; t1++) {
		if(process[t1] == 0) continue;
		else if(process[t1] == 0) {
			for (int t2 = 0; t2 < len; t2++) {
				if (source[t1] == source[t2]) {
					sum[t1]++;
					source[t2] = 1;
				}
			}
			source[t1] = 1;
		}
	}
	sort(sum, sum + len);
	for (int t1 = 0; t1 < len; t1++) {
		if(sum[t1]==0) continue;
		else {
			wait = sum[len - 1] - sum[t1];
			if (prime(wait)) cout << "Lucky Word" << endl << wait << endl;
			else cout << "No Answer" << endl << wait << endl;
			break;
		}
	}
}
