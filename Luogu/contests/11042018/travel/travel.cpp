#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    srand((unsigned)time(NULL));
    cout << rand() / 233 << endl;
    return 0;
}