#include <iostream>
#include <cmath>
using namespace std;
long double T, N, ans;

bool valid(long double N) {
    double sqr = pow(N, 1.0 / 2);
    if(sqr == (int)sqr) return true;
    double cub = pow(N, 1.0 / 3);
    if(cub == (int)cub) return true;
    return false;
}

void genSheet() {
        for(long double N = 1; N < 100; N++) {
            ans = 0;
            for(long double t = 1; t < N; t++) {
            if(valid(t)) {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }

long double getAns(long double N) {
    if(N == 1) return 0;
    long double cnt = 0, lmt = 3, val = 1, crn = 1, ans = 0;
    for(; crn <= N; crn += lmt, lmt++) {
        val++;
    }
    return val;
}

/*
long double getAns(long double N) {
    long double cnt = 0, lmt = 3, val = 1, crn = 1, ans = 0;
    rel:
    for(; cnt < lmt && crn <= N ; cnt++, crn++) {
        ans += val;
    }
    lmt++; val++;
    if(crn <= N) goto rel;
    return ans;
}
*/

int main() {
    ios::sync_with_stdio(false);
    genSheet();
    /*
    cin >> T;
    while(T--) {
        /*
        ans = 0;
        cin >> N;
        for(long double t = 1; t < N; t++) {
            if(valid(t)) {
                // clog << "log: t = " << t << endl;
                ans++;
            }
        }
        cout << ans << endl;
        //
       cin >> N;
       cout << getAns(N) << endl;
    }
    */
    return 0;
}