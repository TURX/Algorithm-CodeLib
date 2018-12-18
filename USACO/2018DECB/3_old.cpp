#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int potential;

struct Bucket {
    int first, second;
    vector<int> capacity[2];
} orig;

void dfs(Bucket& bucket) {
    // Tuesday
    for(int i = 0; i < bucket.capacity[0].size(); i++) {
        Bucket li = bucket;
        bucket.first -= bucket.capacity[0][i];
        bucket.second += bucket.capacity[0][i];
        bucket.capacity[1].push_back(bucket.capacity[0][i]);
        bucket.capacity[0].erase(bucket.capacity[0].begin + i);
        // Wednesday
        for(int j = 0; j < 10; j++) {
            Bucket lj = bucket;
            bucket.second -= bucket.capacity[1][j];
            bucket.first += bucket.capacity[1][j];
            // Thursday
            for(int k = 0; k < 10; k++) {
                Bucket lk = bucket;
                bucket.first -= bucket.capacity[0][k];
                bucket.second += bucket.capacity[0][k];
                for(int m = 0; m < 10; m++)
                bucket = lk;
            }
            bucket = lj;
        }
        bucket = li;
    }
}

int main() {
    //freopen("backforth.in", "r", stdin);
    //freopen("backforth.out", "w", stdout);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> orig.capacity[i][j];
        }
    }
    // Monday
    orig.first = 1000, orig.second = 1000;
    dfs(orig);
    return 0;
}