#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, N;

pair<int, int> getMaxAndMin(vector<int> &arr) {
    int maxValue = arr.back(), minValue = arr.back();

    for (int i = 0; i < N - 1; i += 2) {

        int minCand;
        int maxCand;

        if (arr[i] < arr[i + 1]) {
            minCand = arr[i];
            maxCand = arr[i + 1];
        } else {
            maxCand = arr[i];
            minCand = arr[i + 1];
        }

        minValue = min(minValue, minCand);
        maxValue = max(maxValue, maxCand);
    }

    return make_pair(maxValue, minValue);
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> N;
        vector<int> arr(N);
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        const pair<int, int> &maxAndMin = getMaxAndMin(arr);

        cout << maxAndMin.first << ' ' << maxAndMin.second << '\n';
    }
}
