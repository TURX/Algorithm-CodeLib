#include <iostream>
#include <string>
using namespace std;

const int BSE = 31, MAXU = 10000019, MAXN = 1001;

int N, arti[MAXN << 1], appe[MAXU << 1], lp, rp, wc; // article, appearence, left pointer, right pointer, word count
int ans = MAXN;
bool orig[MAXU << 1], vis[MAXU << 1]; // original vocabulary, visited elements
string S;

inline int getHash(const string s) {
    int len = s.length();
    unsigned int ans = 0;
    for(int t = 0; t < len; t++) {
        ans = (ans * BSE + s[t]) % MAXU;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    while(N--) {
        cin >> S;
        orig[getHash(S)] = true;
    }
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> S;
        arti[t] = getHash(S);
        if(orig[arti[t]] && !vis[arti[t]]) {
            vis[arti[t]] = true;
            wc++;
        }
    }
    if(!wc) {
        cout << "0" << endl;
        return 0;
    } else {
        cout << wc << endl;
    }
    while(true) {
        if(!wc) {
            while(!vis[arti[lp]]) lp++;
            if(lp > N) break;
            ans = min(ans, rp - lp);
            if(appe[arti[lp]] == 1) wc++; // unable to move anymore
            if(appe[arti[lp]] >= 1) appe[arti[lp]]--, lp++;
        } else {
            if(rp > N) break;
            if(vis[arti[rp]]) {
                if(!appe[arti[rp]]) wc--;
                appe[arti[rp]]++;
            }
            rp++;
        }
    }
    cout << ans << endl;
    return 0;
}