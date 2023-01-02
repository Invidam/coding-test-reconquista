#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
//Problem site: https://www.acmicpc.net/problem/1015
// TC: O()
// SC: O()


// TC: O(nlogn)
// SC: O(n)
void solve(vector<p> &valWithAIdx) {
    sort(valWithAIdx.begin(), valWithAIdx.end());

    vector<int> ret(valWithAIdx.size());
    for (int i = 0; i < valWithAIdx.size(); ++i) {
        auto info = valWithAIdx[i];

        ret[info.second] = i;
    }

    for (int val: ret) {
        cout << val << ' ';
    }
}

// TC: O()
// SC: O()
void solve2(vector<p> &valWithAIdx) {
    vector<vector<int>> freq(1001, vector<int>());
    for (int i = 0; i < valWithAIdx.size(); ++i) {
        auto info = valWithAIdx[i];

        freq[info.first].push_back(info.second);
    }
    vector<int> ret(valWithAIdx.size());
    int cnt = 0;

    for (auto arr: freq) {
        for (auto idx: arr) {
            ret[idx] = cnt++;
        }
    }

    for (int val: ret) {
        cout << val << ' ';
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    int N;
    cin >> N;
    vector<p> valWithAIdx;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        valWithAIdx.push_back(p(num, i));
    }

    solve2(valWithAIdx);
    cout << '\n';
    solve(valWithAIdx);


    return 0;
}

