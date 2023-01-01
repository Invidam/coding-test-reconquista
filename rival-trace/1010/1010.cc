#include <iostream>
#include <cstring>

//#include <bits/stdc++.h>
//Problem site: https://www.acmicpc.net/problem/1010

using namespace std;

long long cache[32][32];

int factorialFor(int n) {
    if(n == 0) return 1;
    return n* factorialFor(n-1);
}


long long combFor(int n, int c) {
    if(n < 0 || c < 0) return -1;
    else if(c == 0 || n == c) return 1;



    long long& ret = cache[n][c];

    if(ret != -1) return ret;

    if(c==1) ret = n;
    else ret = combFor(n-1,c-1) + combFor(n-1,c);

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

        memset(cache, -1, sizeof(cache));
        cin >> c >> n;

        cout << combFor(n, c) << '\n';

    }


    return 0;
}

