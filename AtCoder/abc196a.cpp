#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(max(a, b) - min(c, d), min(a, b) - max(c, d)) << endl;
}
