#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, M, N;
vector<int> arr;

int countSum(int targetSum) {
    if (targetSum <= 0) return targetSum == 0;

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        ret += solve(targetSum - arr[i]);
    }

    return ret;
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

        cout << solve(M) << '\n';
    }
}