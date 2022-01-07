// TODO

#include <iostream>
#include <queue>
using namespace std;

#define MAXN 50003

struct Path {
	Path* prev;
	Path* next;
	int id, dist;
	Path(int id, Path* prev, Path* next, int dist) {
		this->id = id;
		this->prev = prev;
		this->next = next;
		this->dist = dist;
	}
	Path() {
		id = 0;
		prev = nullptr;
		next = nullptr;
		dist = MAXN;
	}
	friend bool operator <(Path lhs, Path rhs) {
		return lhs.dist < rhs.dist;
	}
}; // P[MAXN];

priority_queue<Path> P;

int main() {
	int L, N, M, D[MAXN];
	cin >> L >> N >> M;
	Path* last;
	Path* current;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
		if (i > 0) {
			current = new Path(i, last, nullptr, MAXN);
			P.push(*current);
			last->next = current;
			last->dist = D[i] - D[i - 1];
		} else {
			last = new Path(0, nullptr, nullptr, MAXN);
			P.push(*last);
		}
		/*
		if (i > 0) {
			P[i].prev = i - 1;
			P[i - 1].next = i;
			P[i - 1].dist = D[i] - D[i - 1];
		}
		*/
	}
	
	// 动态维护距离数组，移除节点后更新距离，初始mlogn，更新n，共计mn
	for (int i = 0; i < M; i++) {
		Path a, b;
		a = P.top();
	}

	return 0;
}
