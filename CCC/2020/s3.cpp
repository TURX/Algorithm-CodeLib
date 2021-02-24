#include <iostream>
#include <string> 
#include <cstring>
#include <set>
#define MAX_LEN 200000
using namespace std; 

int M, N, i, tot;
string pattern, text;
char P[MAX_LEN], T[MAX_LEN];
set<string> S;

bool compare(char str1[], char str2[]) {
    for (int i = 0; i < MAX_LEN; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

void search(string pat, string txt) {
    M = pat.length(), N = txt.length();
	P[0] = '\0';
	T[0] = '\0';
    for (i = 0; i < M; i++) {
        (P[pat[i]])++;
        (T[txt[i]])++;
    }
    for (i = M; i < N; i++) {
        if (compare(P, T)) {
			if (!S.count(txt.substr(i - M, pat.length()))) {
				S.insert(txt.substr(i - M, pat.length()));
				tot++;
			}
		}
        (T[txt[i]])++;
        T[txt[i - M]]--;
    }
    if (compare(P, T)) {
		if (!S.count(txt.substr(N - M, pat.length()))) {
			S.insert(txt.substr(N - M, pat.length()));
			tot++;
		}
	}
}

int main() {
	string pattern, text;
	cin >> pattern >> text;
    search(pattern, text);
	cout << tot << endl;
    return 0;
}
