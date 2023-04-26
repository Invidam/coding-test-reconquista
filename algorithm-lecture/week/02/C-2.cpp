#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, M, N;
const int INVALID = -1;
const vector<int> INVALID_VECTOR = vector<int>(1, INVALID);
const vector<int> EMPTY_VECTOR = vector<int>();
vector<int> arr;

vector<int> howSum(int targetSum, int idx) {
    if (targetSum < 0) return INVALID_VECTOR;
    if (idx >= N) return targetSum == 0 ? EMPTY_VECTOR : INVALID_VECTOR;
    if (targetSum == arr[idx]) return vector<int>(1, arr[idx]);

    vector<int> cand1 = solve(targetSum - arr[idx], idx);

    if(cand1 != INVALID_VECTOR) {
        cand1.emplace_back(arr[idx]);
        return cand1;
    }

    return solve(targetSum, idx + 1);
}

void print(const vector<int> &ret) {
    for (const auto &item: ret) {
        cout << item << ' ';
    }
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

        const vector<int> &ret = solve(M, 0);
        if(ret == INVALID_VECTOR) {
            cout << "-1";
        } else {
            cout << ret.size() << ' ';
            print(ret);
        }
        cout  << '\n';
    }
}
