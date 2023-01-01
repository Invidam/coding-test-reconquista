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
    // 1 2 4 8 6 2 4

    int a, b;

    while(TC--) {
        cin >> a >> b;

        if(b > 0)
            b = b %4 + 4;

        int ret = 1;
        while(b--) {
            ret *= a;
            ret %= 10;
        }

        cout << ((ret == 0) ? 10 : ret) << '\n';
    }


    return 0;
}

