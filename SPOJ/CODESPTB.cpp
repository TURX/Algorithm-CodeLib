#include <algorithm>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <vector>
using namespace std;

struct MS_R {
    vector<int>* sorted;
    int inversions;
    MS_R(const vector<int>* sorted, const int inversions) {
        this->sorted = new vector<int>();
        copy(sorted->begin(), sorted->end(), back_inserter(*(this->sorted)));
        this->inversions = inversions;
    }
};

MS_R mergesort(const vector<int>& to_sort) {
    int n = to_sort.size();
    if (n <= 1) return MS_R(&to_sort, 0);
    int mid = n / 2;
    vector<int> left_part;
    for (int i = 0; i < mid; i++) left_part.push_back(to_sort[i]);
    vector<int> right_part;
    for (int i = mid; i < n; i++) right_part.push_back(to_sort[i]);
    MS_R left_r = mergesort(left_part);
    const vector<int>& left_sorted = *(left_r.sorted);
    MS_R right_r = mergesort(right_part);
    const vector<int>& right_sorted = *(right_r.sorted);
    int left_ptr = 0, right_ptr = 0;
    vector<int> sorted;
    int cross_inv = 0;
    while (left_ptr < mid && right_ptr < n - mid) {
        if (left_sorted[left_ptr] <= right_sorted[right_ptr]) {
            sorted.push_back(left_sorted[left_ptr++]);
        } else {
            cross_inv += mid - left_ptr;
            sorted.push_back(right_sorted[right_ptr++]);
        }
    }
    if (sorted.size() < n) {
        while (left_ptr < mid) {
            sorted.push_back(left_sorted[left_ptr++]);
        }
        while (right_ptr < n - mid) {
            sorted.push_back(right_sorted[right_ptr++]);
        }
    }
    return MS_R(&sorted, left_r.inversions + right_r.inversions + cross_inv);
}

int main() {
    // freopen("CODESPTB.in", "r", stdin);
    // freopen("CODESPTB.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A = vector<int>(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        MS_R R = mergesort(A);
        // for (int i = 0; i < N; i++) cout << R.sorted[i] << " ";
        // cout << endl;
        cout << R.inversions << endl;
    }
}
