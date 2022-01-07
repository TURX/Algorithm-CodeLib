#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;

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

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	while (cin >> N) {
		if (N == 0) break;
		rk.clear();
		for (int i = 0 ; i < N; i++) {
			string name;
			int gold, silver, bronze;
			cin >> name >> gold >> silver >> bronze;
			rk.push_back(Country(name, gold, silver, bronze));
		}
		Country* canada;
		int maxGold = -1, maxSilver = -1, maxBronze = -1;
		for (int i = 0; i < N; i++) {
			if (rk[i].name == "Canada") canada = &rk[i];
			maxGold = max(maxGold, rk[i].gold);
			maxSilver = max(maxSilver, rk[i].silver);
			maxBronze = max(maxBronze, rk[i].bronze);
		}
		if (maxGold == canada->gold || maxSilver == canada->silver || maxBronze == canada->bronze) {
			cout << "Canada wins!" << endl;
		} else {
			cout << "Canada cannot win." << endl;
		}
	}
	return 0;
}
