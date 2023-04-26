#include <iostream>
#include <bits/stdc++.h>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int MOD = 1000000;
//Problem site: https://www.acmicpc.net/problem/

// TC: O()
// SC: O()

vector<int> cache(5001, -1);


bool isValid(string &str) {

    if(str.size() == 0 || str.size() > 5000) return false;

    return ('1' <= str[0] && str[0] <= '9');
}

bool isTwoDigit(const string &str, int idx) {
    int num = stoi(str.substr(idx, 2));
    return 10 <= num && num <= 26;
}

int solve(string &str, int idx = 0) {
    if(idx == 0 && !isValid(str))
        return 0;
    if (idx >= str.size()) {
        return 1;
    }
    int &ret = cache[idx];

    if (ret != -1) return ret;

    int cand1 = 0;

    if(str[idx] != '0')
        cand1 = solve(str, idx + 1);

    int cand2 = 0;

    if (idx + 1 < str.size() && isTwoDigit(str, idx))
        cand2 = solve(str, idx + 2);

    return ret = ((cand1 + cand2) % MOD);
}

int main() {

    FAST_IO;

    string str;
    cin >> str;


    cache = vector<int>(5001, -1);
    cout << solve(str);


    return 0;
}