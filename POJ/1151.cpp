// Atlantis
// Algorithm: 扫描线，线段树

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 101

struct Point {
    double x, y1, y2;
    short int arg;
};

int N, totEle, totAns, dat[MAXN];
double x1, x2, y1, y2;
vector<double> xCollection, yCollection;
vector<Point> M;
map<int, double> yVal;

inline bool cmp(const Point& lhs, const Point& rhs) {
    return lhs.x < rhs.x;
}

inline void update(const int& l, const int& r, const short int& val) {
    for(int t = l; t < r; t++) dat[t] += val;
}

inline int enquiry() {
    int ans = 0;
    for(int t = 0; t < totEle; t++) if(dat[t]) ans += yCollection[t];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int t = 0; t < N; t++) {
        cin >> x1 >> y1 >> x2 >> y2;
        xCollection.push_back(x1), xCollection.push_back(x2);
        yCollection.push_back(y1), yCollection.push_back(y2);
        M.push_back({x1, y1, y2, 1}); // Left edge.
        M.push_back({x2, y1, y2, -1}); // Right edge.
    }
    vector<double>::iterator iter = unique(yCollection.begin(), yCollection.end());
    yCollection.erase(iter, yCollection.end());
    for(int t = 0; t < yCollection.size(); t++) yVal[yCollection[t]] = t;
    sort(M.begin(), M.end(), cmp);
    totEle = M.size();
    for(int t = 0; t < totEle - 1; t++) {
        update(yVal[M[t].y1], yVal[M[t].y2], M[t].arg);
        totAns += (M[t + 1].x - M[t].x) * enquiry();
    }
    cout << "Test case #1\nTotal explored area: " << totAns << endl;
    return 0;
}