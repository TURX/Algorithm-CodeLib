#include <iostream>
using namespace std;
int N, T, happyDay, happyDayMin, cnt;
bool happy[100000000], happy2[1000000];

bool readHappy(int& val) {
	if(val < 100000000) return happy[val]; else return happy2[val - 100000000];
}

void writeHappy(int& val) {
	if(val < 100000000) happy[val] = true; else happy2[val - 100000000] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> T;
	for(int t = 0; t < N; t++) {
		cin >> happyDay;
		if(t == 0) happyDayMin = happyDay;
		for(int i = happyDay; i < happyDay + T; i++) {
			writeHappy(i);
		}
	}
	for(int t = happyDayMin; t < happyDay + T; t++) {
		if(readHappy(t)) cnt++;
	}
	/*
	clog << "HPDM=" << happyDayMin << "; HPD=" << happyDay << endl;
        clog << "ARR=";
	for(int t = happyDayMin; t < happyDay + T; t++) {
		clog << happy[t] << " ";
	}
	*/
	cout << cnt << endl;
	return 0;
}
