#include <iostream>
#include <vector>
using namespace std;

struct BouncingDiagonal {
    int startingNum = -1;
    int weight = -1;
    friend bool operator<(BouncingDiagonal lhs, BouncingDiagonal rhs) {
        if (lhs.weight != rhs.weight)
            return lhs.weight < rhs.weight;
        return lhs.startingNum < rhs.startingNum;
    }
};

int calculateDiagonalWeight(const vector<vector<int>>& matrix, int x, int y, bool upward, int currentWeight) {
    currentWeight += matrix[x][y];
    if (x == matrix.size() - 1) return currentWeight;
    if (upward) {
        if (y - 1 < 0) return calculateDiagonalWeight(matrix, x + 1, y + 1, false, currentWeight);
        return calculateDiagonalWeight(matrix, x + 1, y - 1, upward, currentWeight);
    } else {
        if (y + 1 >= matrix.size()) return calculateDiagonalWeight(matrix, x + 1, y - 1, true, currentWeight);
        return calculateDiagonalWeight(matrix, x + 1, y + 1, upward, currentWeight);
    }
}

vector<int> bouncingDiagonals(vector<vector<int>> matrix) {
    BouncingDiagonal bouncingDiagonals[matrix.size()];
    for (int i = 0; i < matrix.size(); i++) {
        bouncingDiagonals[i].startingNum = matrix[i][0];
        bouncingDiagonals[i].weight = calculateDiagonalWeight(matrix, i, 0, true, 0);
    }
    sort(bouncingDiagonals, bouncingDiagonals + matrix.size());
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++) {
        ans.push_back(bouncingDiagonals[i].startingNum);
    }
    return ans;
}

int main() {
	vector<int, vector<int>> = [[2, 3, 2],
          [0, 2, 5],
          [1, 0, 1]];
}
