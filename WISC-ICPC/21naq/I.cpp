#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

enum Operator { And, Or };
struct Implicative {
	Implicative(Operator op, vector<string> operands, string toAdd) {
		this->op = op;
		this->operands = operands;
		this->toAdd = toAdd;
	}
	Operator op;
	vector<string> operands;
	string toAdd;
};

unordered_set<string> absolutes;
unordered_set<string> counted;
vector<Implicative> implicatives;
unordered_map<string, vector<int> > implicativesMap;
queue<string> Q;
int ans = 0;

int main() {
	#ifdef VSCODE_DBG
		freopen("test.in", "r", stdin);
	#endif
	cin.tie(0)->sync_with_stdio(0);
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		string s;
		getline(cin, s);
		if (s == "") {
			i--;
			continue;
		}
		if (s.length() <= 2 || s.substr(0, 2) != "if") {
			if (absolutes.find(s) == absolutes.end()) {
				absolutes.insert(s);
				counted.insert(s);
			}
		} else { // implicative
			s.erase(0, 3); // "if "
			size_t thenIndex = s.find(" then ");
			string toAdd = s.substr(thenIndex + 6, s.length() - thenIndex - 6);
			s = s.substr(0, thenIndex);
			Operator op;
			if (s.find("and") == string::npos) op = Or;
			else op = And;
			vector<string> operands;
			if (op == And) {
				size_t nextOp = s.find(" and ");
				while (nextOp != string::npos) {
					operands.push_back(s.substr(0, nextOp));
					s.erase(0, nextOp + 5);
					nextOp = s.find(" and ");
				}
				operands.push_back(s);
			} else {
				size_t nextOp = s.find(" or ");
				while (nextOp != string::npos) {
					operands.push_back(s.substr(0, nextOp));
					s.erase(0, nextOp + 4);
					nextOp = s.find(" or ");
				}
				operands.push_back(s);
			}
			int id = implicatives.size();
			implicatives.push_back(Implicative(op, operands, toAdd));
			for (string operand : operands) {
				implicativesMap[operand].push_back(id);
			}
		}
	}
	for (const auto& absolute : absolutes) {
		Q.push(absolute);
	}
	while (!Q.empty()) {
		string current = Q.front();
		Q.pop();
		if (implicativesMap[current].size() == 0) continue;
		for (const int& id : implicativesMap[current]) {
			if (counted.find(implicatives[id].toAdd) != counted.end()) continue;
			bool evaluation;
			switch (implicatives[id].op) {
				case And:
					evaluation = true;
					for (const auto& operand : implicatives[id].operands) {
						if (counted.find(operand) == counted.end()) {
							evaluation = false;
							break;
						}
					}
					break;
				case Or:
					evaluation = false;
					for (const auto& operand : implicatives[id].operands) {
						if (counted.find(operand) != counted.end()) {
							evaluation = true;
							break;
						}
					}
					break;
			}
			if (evaluation == true) {
				counted.insert(implicatives[id].toAdd);
				Q.push(implicatives[id].toAdd);
			}
		}
	}
	cout << counted.size() << endl;
}
