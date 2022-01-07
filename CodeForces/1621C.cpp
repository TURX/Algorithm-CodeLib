/*

q'[i] = q[p[i]] p=[4, 2, 1, 3]
1, 2, 3, 4 => ask any identity permutation
4, 2, 1, 3 => ask 3 q'[3]=q[p[3]]=1->p[3]=1
3, 2, 4, 1 => ask 3 q'[3]=q[p[3]]=q[1]=p[1]=4
1, 2, 3, 4 => ask any
4, 2, 1, 3 => ask 2 q'[2]=p[2]=2

q'[i] = q[p[i]] p=[4, 2, 5, 3, 1]
1, 2, 3, 4, 5 => ask 1: q(0)[1]=1
4, 2, 5, 3, 1 => ask 1: q(1)[1]=4=q(0)[p[1]]=p[1]
3, 2, 1, 5, 4 => ask 1: q(2)[1]=3=q(1)[4]=q(0)[p[4]]=p[4]
5, 2, 4, 1, 3 => ask 1: q(3)[1]=5=q(2)[4]=q(1)[p[4]]=q(1)[3]=q(0)[p[3]]=p[3]
1, 2, 3, 4, 5 => ask 1: again
4, 2, 5, 3, 1 => ask 2: q(1)[2]=2=p[2]
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int ask(int index) {
	cout << "? " << index << endl;
	cout.flush();
	int result;
	cin >> result;
	return result;
}

void submit(string answer) {
	cout << "! " << answer << endl;
	cout.flush();
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 0) {
			submit("");
			continue;
		}
		if (N == 1) {
			submit("1");
			continue;
		}
		if (N == 2) {
			ask(1);
			int one = ask(1);
			if (one == 2) submit("2 1");
			else submit ("1 2");
			continue;
		}
		int P[N + 1];
		memset(P, -1, sizeof(P));
		for (int i = 1; i <= N; i++) {
			if (P[i] == -1) {
				int initial = ask(i); // q(0)[1]=1
				int last = initial;
				int current;
				while (true) {
					current = ask(i);
					P[last] = current;
					last = current;
					if (current == initial) break;
				}
			}
		}
		string result = "";
		for (int i = 1; i <= N; i++) {
			result += to_string(P[i]) + " ";
		}
		submit(result);
	}
}
