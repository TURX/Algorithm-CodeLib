#include <iostream>
using namespace std;

int n, c, score, judge, currentScore, conti;
double scoreA[1003], totScore;

struct ScoreData {
    double p, s;
} scoreData[1003];

struct JudgeData {
    double p, t;
} judgeData[1003];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> score >> judge;
    for(int t = 0; t < score; t++) {
        cin >> c >> scoreData[c].p >> scoreData[c].s;
        // scoreDataPtr++;
    }
    for(int t = 0; t < judge; t++) {
        cin >> c >> judgeData[c].p >> judgeData[c].t;
        // judgeDataPtr++;
    }
    for(int t = 1; t <= n; t++) {
        cin >> scoreA[t];
    }
    scoreA[0] = -1;
    for(int t = 1; t <= n; t++) {
        if(scoreA[t] == scoreA[t - 1]) conti++;
        else conti = 0;
        for(int j = conti; j > 0; j--) {
            totScore += scoreData[j].s * scoreData[j].p / 100;
            if(scoreA[t] < 2 && scoreA[t] > 0 && judgeData[conti].t) {
                for(int i = t + 1; i <= t + judgeData[conti].t; i++) {
                    if(scoreA[i] < 2 && scoreA[i] > 0) {
                        scoreA[i] += judgeData[conti].p / 100;
                    }
                }
            }
        }
        if(scoreA[t] >= 2) totScore += (double)(2 * (conti + 1));
        else totScore += (scoreA[t] * (double)(conti + 1));
    }
    cout << totScore << endl;
    return 0;
}