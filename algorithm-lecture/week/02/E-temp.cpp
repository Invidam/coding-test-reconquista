#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int INVALID = -1;

const vector<int> INVALID_VECTOR = vector<int>(1, INVALID);
const vector<int> EMPTY_VECTOR = vector<int>();

const vector<vector<int>> INVALID_2D_VECTOR = vector<vector<int>>(1, INVALID_VECTOR);
const vector<vector<int>> EMPTY_2D_VECTOR = vector<vector<int>>();

int TC, M, N;
vector<int> arr;

vector<vector<int>> bestSum(int targetSum, int idx) {
    if(targetSum <= 0) return targetSum == 0 ? EMPTY_2D_VECTOR : INVALID_2D_VECTOR;
    if(idx >= N) return idx == 0 ? EMPTY_2D_VECTOR : INVALID_2D_VECTOR;

    return solve(targetSum - arr[idx], 0) + solve(targetSum, idx + 1);
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> M >> N;

        arr = vector<int>(N);
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        cout << solve(M, 0) << '\n';
    }
}
