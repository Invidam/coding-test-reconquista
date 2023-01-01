#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

//Problem site: https://www.acmicpc.net/problem/1009

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;

    cin >> TC;

    int a, b;

    while(TC--) {
        cin >> a >> b;

        int ret = 1;
        while(b--) {
            ret *= a;
            ret %= 10;
        }

        cout << ((ret == 0) ? 10 : ret) << '\n';
    }


    return 0;
}

