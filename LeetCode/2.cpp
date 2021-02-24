#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkp(string p) {
    for (int t = 0; t < p.length(); t++) if (p[t] != '*') return false;
    return true;
}

bool isMatch(string s, string p)
{
    if (!p.length()) return !s.length();
    if (checkp(p)) return true;
    int ms, mp = 0;
    for (ms = 0; ms < s.length(); ms++) {
        if (p[mp] == '*') {
            while (p[mp] == '*') mp++;        
            if (!p[mp]) return true;
            for (int t = ms; t < s.length(); t++) {
                if (s[t] == p[mp]) {
                    if(isMatch(s.substr(t, s.length()), p.substr(mp, p.length()))) {
                        return true;
                    }
                }
                if (p[mp] == '?') {
                    if(isMatch(s.substr(t + 1, s.length()), p.substr(mp + 1, p.length()))) {
                        return true;
                    }
                }
            }
        }
        if (s[ms] == p[mp] || p[mp] == '?') {
            mp++;
            continue;
        }
        return false;
    }
    if (ms < s.length() || mp < p.length()) {
        if (mp < p.length()) {
            if (checkp(p.substr(mp, p.length()))) return true;
        }
        return false;
    }
    return true;
}

int main()
{
    string S, P;
    cin >> S >> P;
    cout << isMatch(S, P) << endl;
    return 0;
}