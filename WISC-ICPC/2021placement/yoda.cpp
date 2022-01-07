#include <iostream>
using namespace std;

string N, M, outN, outM;
bool swapped = 0;
int nptr = 0;

string trimZero(string in) {
	if (in.length() == 0 || in[0] != '0') return in;
	bool found = false;
	string out;
	for (int i = 0; i < in.length(); i++) {
		if (found == true) {
			out.push_back(in[i]);
		}
		if (found == false && in[i] != '0') {
			found = true;
			out.push_back(in[i]);
		}
	}
	if (found == false) return "0";
	else return out;
}

int main() {
	cin >> N >> M;
	if (M.length() > N.length()) {
		swap(N, M);
		swapped = 1;
	} // N is the most lengthy
	for (int i = 0; i < N.length() - M.length(); i++) {
		outN.push_back(N[i]);
		nptr++;
	}
	for (int i = 0; i < M.length(); i++) {
		if (N[nptr + i] >= M[i]) {
			outN.push_back(N[nptr + i]);
		}
		if (N[nptr + i] <= M[i]) {
			outM.push_back(M[i]);
		}
	}
	if (swapped) swap(outN, outM);
	outN = trimZero(outN);
	outM = trimZero(outM);
	if (outN.length() == 0) outN = "YODA";
	if (outM.length() == 0) outM = "YODA";
	cout << outN << endl << outM << endl;
}
