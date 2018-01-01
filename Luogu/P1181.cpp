#include<iostream>
using namespace std;
int n,now,temp=0; // n≤100000，now与temp都为临时变量
unsigned long long m; // m≤10^9
int ans=1; // 就是全是0也至少有一段
int main() {
	ios::sync_with_stdio(false); // 提高iostream效率
	cin>>n>>m; // 输入
	for(int t=0;t<n;t++) {
		cin>>now; // 输入当前数
		if((temp+=now)>m) { // 如果比m大，就要分段
			temp=0; // temp清零（重算新的一段）
			ans++; // 段数++
			temp+=now; // 从0开始算temp的值
		}
	}
	cout<<ans<<endl; // 输出段数
}