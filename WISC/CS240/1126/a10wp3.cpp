#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

int N;
vector<pair<int, int>> R, RR, RC;
unordered_map<pair<int, int>, bool, pair_hash> visited;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		R.push_back(make_pair(a, b));
		RR.push_back(make_pair(b, a));
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (RR[i].second == R[j].first) {
				pair<int, int> pending = make_pair(RR[i].first, R[j].second);
				if (!visited[pending]) {
					visited[pending] = true;
					RC.push_back(pending);
				}
			}
	for (int i = 0; i < RC.size(); i++)
		cout << "(" << RC[i].first << ", " << RC[i].second << ")" << endl;
}
