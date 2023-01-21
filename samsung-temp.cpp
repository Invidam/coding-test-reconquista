#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

//Problem site: https://www.acmicpc.net/problem/

// TC: O()
// SC: O()

void printByIndex(int idx, int ret) {
    cout << '#' << (idx + 1) << ' ' << ret << '\n';
}

int solve() {

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {

        printByIndex(i, solve());
    }



    return 0;
}