#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int potential;

struct Bucket {
    int first, second;
    int capacity[2][20];
} orig;

map<int, bool> visited;

int findAvailable(const Bucket& bucket, const int& para) {
    for(int t = 0; t < 20; t++) if(!bucket.capacity[para][t]) return t;
    return -1;
}

void dfs(Bucket& bucket) {
    // Tuesday
    for(int i = 0; i < 10; i++) {
        Bucket li = bucket;
        bucket.first -= bucket.capacity[0][i];
        bucket.second += bucket.capacity[0][i];
        bucket.capacity[1][findAvailable(bucket, 1)] = bucket.capacity[0][i];
        bucket.capacity[0][i] = 0;
        // Wednesday
        for(int j = 0; j < 20; j++) {
            if(!bucket.capacity[1][j]) continue;
            Bucket lj = bucket;
            bucket.second -= bucket.capacity[1][j];
            bucket.first += bucket.capacity[1][j];
            bucket.capacity[0][findAvailable(bucket, 0)] = bucket.capacity[0][j];
            bucket.capacity[1][j] = 0;
            // Thursday
            for(int k = 0; k < 20; k++) {
                if(!bucket.capacity[0][k]) continue;
                Bucket lk = bucket;
                bucket.first -= bucket.capacity[0][k];
                bucket.second += bucket.capacity[0][k];
                bucket.capacity[1][findAvailable(bucket, 1)] = bucket.capacity[0][k];
                bucket.capacity[0][k] = 0;
                // Friday
                for(int m = 0; m < 20; m++) {
                    if(!bucket.capacity[1][m]) continue;
                    Bucket lm = bucket;
                    bucket.second -= bucket.capacity[1][m];
                    bucket.first += bucket.capacity[1][m];
                    if(!visited[bucket.first]) {
                        potential++;
                        visited[bucket.first] = true;
                    }
                    bucket = lm;
                }
                bucket = lk;
            }
            bucket = lj;
        }
        bucket = li;
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> orig.capacity[i][j];
        }
    }
    // Monday
    orig.first = 1000, orig.second = 1000;
    dfs(orig);
    cout << potential << endl;
    return 0;
}