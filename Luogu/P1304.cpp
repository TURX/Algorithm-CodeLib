#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, j1, j2, p1 = 0, p2 = 0;
    cin >> a;
    for (int w = 4; w <= a; w += 2)
        for (int z = 2; z <= w / 2; z++)
        {
            p1 = 0;
            p2 = 0;
            for (int y = 2; y <= sqrt(z); y++)
                if (z % y == 0)
                {
                    p1 = 1;
                    break;
                }
            if (p1 == 1)
                continue;
            j1 = z;
            for (int x = 2; x <= sqrt(w - z); x++)
                if ((w - z) % x == 0)
                {
                    p2 = 1;
                    break;
                }
            if (p2 == 1)
                continue;
            j2 = w - z;
            cout << w << "=" << j1 << "+" << j2 << endl;
            break;
        }
    return 0;
}