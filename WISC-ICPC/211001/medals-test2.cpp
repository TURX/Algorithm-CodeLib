#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Country {
	string name;
	int gold, silver, bronze;
	Country(string name, int gold, int silver, int bronze) {
		this->name = name;
		this->gold = gold;
		this->silver = silver;
		this->bronze = bronze;
	}
};

vector<Country> rk;

bool solve(int numCountries, int numMedals, int j, int k, int l) {
	int canada;
	int scores[numCountries], maxScore = -1;
	for (int i = 0; i < numCountries; i++) {
		if (rk[i].name == "Canada") canada = i;
		scores[i] = rk[i].gold * pow(numMedals, j) + rk[i].silver * pow(numMedals, k) + rk[i].bronze * pow(numMedals, l);
		maxScore = max(maxScore, scores[i]);
	}
	return maxScore == scores[canada];
}

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	int N, totMedals;
	while (cin >> N) {
		if (N == 0) break;
		totMedals = 0;
		rk.clear();
		for (int i = 0 ; i < N; i++) {
			string name;
			int gold, silver, bronze;
			cin >> name >> gold >> silver >> bronze;
			totMedals += gold + silver + bronze;
			rk.push_back(Country(name, gold, silver, bronze));
		}
		bool solved = false;
		for (int i = 0; i <= 1; i++) {
			if (solved) break;
			for (int j = 0; j <= 1; j++) {
				if (solved) break;
				for (int k = 0; k <= 1; k++) {
					if (solve(N, 100, i, j, k)) {
						solved = true;
						break;
					}
				}
			}
		}
		if (solved) cout << "Canada wins!" << endl;
		else cout << "Canada cannot win." << endl;
	}
	return 0;
}
