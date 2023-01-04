#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;
//Problem site: https://www.acmicpc.net/problem/1024
// TC: O(L)
// SC: O(1)


int N, L, diff;

int solve() {
    int endNum;
    for (diff = L - 1; diff < 100; ++diff) {

        // N = (B + A)(B - A + 1) / 2 ,  [B = endNum, A = endNum - diff]
        // -> B = (diff * diff + diff + 2 * N) / 2 * (diff + 1)
        int numerator = diff * diff + diff + 2 * N;
        int denominator = 2 * (diff + 1);

        if (numerator % denominator) {
            continue;
        }
        endNum = numerator / denominator;

        //음수 예외 처리
        if (endNum < diff) continue;
        return endNum;
    }
    return -1;
}

void printFrom(int ret) {
    for (int i = 0; i <= diff; ++i) {
        cout << ret - diff + i << ' ';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    int ret = solve();

    if (ret == -1) {
        cout << "-1";
        return 0;
    }
    printFrom(ret);

    return 0;
}