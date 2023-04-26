#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

// TC: O()
// SC: O()

int ret;
int N;
//string ret

void printByIndex(int idx) {
    cout << '#' << (idx + 1) << ' ' << ret << '\n';
}

void solve() {

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> N;

        solve();
        printByIndex(i);
    }



    return 0;
}