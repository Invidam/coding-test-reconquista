#include <iostream>
#include <cstring>

//#include <bits/stdc++.h>
//Problem site: https://www.acmicpc.net/problem/1010

using namespace std;

int combFor(int n, int c) {
    int ret = 1;

    for (int i = 0; i < c; ++i) {
        ret = ret * (n-i) / (i+1);
    }
    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;

    cin >> TC;

    int n, c;

    while(TC--) {
        cin >> c >> n;

        cout << combFor(n, c) << '\n';
    }


    return 0;
}

