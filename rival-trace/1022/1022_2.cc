#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
//Problem site: https://www.acmicpc.net/problem/1015
const int MAX_SIZE = 51;

int r1, r2, c1, c2;

int squareFor(int num) {
    return (2 * num) * (2 * num);
}

int squareForMax(int num) {
    return (2 * num + 1) * (2 * num + 1);
}


int maxRCFor(int r, int c) { return max(abs(r), abs(c)); }


int valueFor(int r, int c) {
    int ret;
    int maxRC = maxRCFor(r, c);
    int squareNum = squareFor(maxRC);

    int rDiff = maxRC - abs(r);
    int cDiff = maxRC - abs(c);


    if (r == 0 && c == 1) return 2;


    if (r < 0 && c < 0) {
        int edgeNum = squareNum + 1;

        ret = edgeNum - cDiff + rDiff;

    } else if ((r < 0 && c >= 0)) {
        int edgeNum = squareNum - 2 * maxRC + 1;

        ret = edgeNum + cDiff - rDiff;
    } else if ((r >= 0 && c < 0)) {
        int edgeNum = squareNum + 2 * maxRC + 1;

        ret = edgeNum + cDiff - rDiff;
    } else if ((r == maxRC)) {
        int edgeNum = squareForMax(maxRCFor(r, c));

        ret = edgeNum - cDiff;
    } else if ((c == maxRC)) {
        int edgeNum = squareForMax(maxRCFor(r - 1, c - 1));

        ret = edgeNum + rDiff;
    }
    return ret;
}

//자릿수 찾기 위해 사용, 정수 자릿수 구함.
int lenOf(int maxVal) {
    int ret = 0;

    while (maxVal > 0) {
        maxVal /= 10;
        ++ret;
    }

    return ret;
}

//배열을 출력
int getMaxResult() {
    int ret = 1;
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            ret = max(ret, valueFor(i, j));
        }
    }

    return ret;
}

void printArr() {
    int cntLen = lenOf(getMaxResult());
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {

            printf("%*d ", cntLen, valueFor(i, j));
        }

        printf("\n");
    }
}

// TC: O((r2-r1)^2)
// SC: O(1)
void solve() {
    printArr();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r1 >> c1 >> r2 >> c2;

    solve();

    return 0;
}