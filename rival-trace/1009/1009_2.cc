#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

//Problem site: https://www.acmicpc.net/problem/1009

int onlyLastDigitFor(int num, int p) {
    if(p <= 0) return 1;
    if(p % 2 == 1) {
        return (onlyLastDigitFor(num, p -1) * num) % 10;
    } else {
        return (onlyLastDigitFor(num, p / 2) * onlyLastDigitFor(num, p / 2)) % 10;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;

    cin >> TC;

    int a, b;

    while(TC--) {
        cin >> a >> b;

        int ret = onlyLastDigitFor(a,b);

        cout << ((ret == 0) ? 10 : ret) << '\n';
    }


    return 0;
}

