#include <iostream>
#include <queue>
using namespace std;
int N, S, temp_C; long long temp_Y,ans=0;
struct Machine {
	int C;
	long long Y;
	long long sum() {
		return Y * ( C + S * N );
	}
	friend bool operator < (Machine left, Machine right) {
		return left.sum() < right.sum();
	}
};
Machine mid_m;
Machine make_m(int C=0,long long Y=0) {
	Machine temp_m;
	temp_m.C = C; temp_m.Y = Y;
}
priority_queue<Machine> M;
int main() {
	ios::sync_with_stdio(false); 
	cin>>N>>S;
	for(int t=0; t<N; t++) {
		cin>>temp_C>>temp_Y;
		M.push(make_m(temp_C, temp_Y));
	}
	while(!M.empty()) {
		mid_m = M.top();
		ans+=mid_m.sum();
		M.pop();
	}
	cout<<ans<<endl;
}
