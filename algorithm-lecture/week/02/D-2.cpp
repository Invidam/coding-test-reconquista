#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, M, N;
vector<int> arr;

int solve(int targetSum, int idx) {
    if(targetSum <= 0) return targetSum == 0;
    if(idx >= N) return idx == 0;

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
