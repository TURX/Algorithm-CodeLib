#include <iostream>
#include <algorithm>
using namespace std;
struct data
{
  int k, s; // k num, s grade
};
bool compare(data lhs, data rhs)
{
    if (lhs.s != rhs.s)
		return lhs.s > rhs.s;
    else                  
		return lhs.k < rhs.k;
}
int main()
{
	ios::sync_with_stdio(false);
	// Declare & Input
    int n, m;
    cin >> n >> m;
    data dat[n];
    for (int i = 0; i < n; i++)	cin >> dat[i].k >> dat[i].s;
    // Sort
    sort(dat, dat + n, compare);
    // Calc the people
    int people = m * 1.5;
	// Calc the line
	int line = dat[people-1].s;
	// Calc the people
	for (people = 0; dat[people].s >= line; people++);
	// Output
	cout << line << " " << people << endl;
	for (int i = 0; i < people; i++) cout << dat[i].k << " " << dat[i].s << endl;
    return 0;
}
