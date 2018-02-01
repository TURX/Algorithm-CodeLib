#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#include <cstdio>

struct Position {
    int x, y;
};
struct Route {
	queue<Position> que;
	int len;
    friend bool operator <(Route l, Route r) {
        return l.len < r.len;
    }
};
bool record[1003][1003];
char hiramizawa[1003][1003];
int N, M, people, nextstep[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
map<Position, char> ch;
Position S;
priority_queue<Route> route;

Position make_pos(int x, int y) {
    Position temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
Route make_route(queue<Position> que, int len) {
	Route temp;
	temp.que = que;
	temp.len = len;
	return temp;
}
void scan() {
    int i = 0, j = 0;
    while(i++ < N)
        while(j++ < M) {
            if(hiramizawa[i][j] == 'S') {
                S.x = i;
                S.y = j;
            }
            if(hiramizawa[i][j] != '*') {
            	ch.insert(pair<Position, char>(make_pos(i, j), hiramizawa[i][j]));
                people++;
            }
        }
}
void output() {
	Route dest = route.top();
	for(int t = 0; t < people; t++) {
		cout << ch.at(dest.que.front()) << "(" << dest.que.front().x << "," << dest.que.front().y << ")";
		if(t < people - 1) cout << "->";
	}
	cout << endl;
	cout << dest.len << endl;
}
double distance(Position l, Position r) {
    return sqrt((double)((l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y)));
}
Position fromque(queue<Position> que, int cnt) {
	for(int t = 0; t < cnt; t++) {
		que.pop();
	}
	return que.front();
}
void dfs(Position pos, queue<Position> que, double len) {
    int x = pos.x, y = pos.y;
    if(hiramizawa[x][y] != '*') {
    	que.push(pos);
    	if(que.size() > 1) {
    		len += distance(pos, fromque(que, que.size() - 1));
		}
	}
    int tx, ty, k;
    if(x == S.x && y == S.y) {
      if(que.size() == people) {
          route.push(make_route(que, (int)len));
      }
      return;
    }
    for(k = 0; k < 4; k++) {
        tx = x + nextstep[k][0];
        ty = y + nextstep[k][1];
        if (tx >= 0 && tx < N && ty >= 0 && ty < M && (record[tx][ty] == 0 || (tx == S.x && ty == S.y))) {
            record[tx][ty] = true;
            dfs(make_pos(tx, ty), que, len);
            record[tx][ty] = false;
        }
    }
}
int main() {
    freopen("secret/sample/T20944/1.in","r",stdin);
    cin >> N >> M;
    {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> hiramizawa[i][j];
    }
    scan();
    queue<Position> que;
    dfs(make_pos(S.x, S.y), que, 0);
    output();
    cout << "Y" << endl;
}
