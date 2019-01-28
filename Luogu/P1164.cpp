#include <iostream>
using namespace std;

#define MAXN 1001

int N, M, menu[MAXN], dp[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for(int t = 1; t <= N; t++) cin >> menu[t];
	for(int dishCount = 1; dishCount <= N; dishCount++) {
		for(int outMoney = 1; outMoney <= M; outMoney++) {
			if(outMoney == menu[dishCount]) dp[dishCount][outMoney] = dp[dishCount - 1][outMoney] + 1;
			if(outMoney > menu[dishCount]) dp[dishCount][outMoney] = dp[dishCount - 1][outMoney] + dp[dishCount - 1][outMoney - menu[dishCount]];
			if(outMoney < menu[dishCount]) dp[dishCount][outMoney] = dp[dishCount - 1][outMoney];
		}
	}
	cout << dp[N][M] << endl;
	return 0;
}