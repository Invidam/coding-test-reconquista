#include <iostream>
#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int MOD = 1e9;
//Problem site: https://www.acmicpc.net/problem/

// TC: O()
// SC: O()

int cache[201][201];


int solve(int N, int K) {
    if(K == 0) return N == 0;
    if(N == 0) return 1;

    int &ret = cache[N][K];
    if (ret != -1) return ret;

    ret = 0;

    for (int i = 0; i < N + 1; ++i) {
        ret += solve(N - i, K -1);
        ret %= MOD;
    }

    return ret;
}

int main() {

    FAST_IO;

    memset(cache, -1, sizeof(cache));

    int nn, kk;

    cin >> nn >> kk;
    cout << solve(nn, kk);

    return 0;
}