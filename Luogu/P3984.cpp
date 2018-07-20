#include <iostream>
using namespace std;
int N, T, happyDay, lastHappyDay, cnt, gap;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> T;
	for(int t = 0; t < N; t++) {
		cin >> happyDay;
        if(t) {
            if((happyDay - lastHappyDay) > 0) gap += happyDay - lastHappyDay;
        }
        clog << "LHD: " << lastHappyDay << "; HD: " << happyDay << endl;
        lastHappyDay = happyDay + T;
	}
	/*
	clog << "HPDM=" << happyDayMin << "; HPD=" << happyDay << endl;
        clog << "ARR=";
	for(int t = happyDayMin; t < happyDay + T; t++) {
		clog << happy[t] << " ";
	}
	*/
	cout << happyDay + T - gap - 1 << endl;
	return 0;
}
