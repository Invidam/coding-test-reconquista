#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
//Problem site: https://www.acmicpc.net/problem/1022

const int MAX_VAL = 5000;
const int MAX_IDX = 2 * MAX_VAL + 1;

static const int ROW_MAX = 51;
static const int COL_MAX = 6;

const int offset[4][2] = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0}
};

int r1, r2, c1, c2;

//toY,toX는 y,x 좌표계에서 1e8, 1e8의 RC좌표계로의 변환
int toYIdx(int val) {
    return MAX_VAL - val;
}

int toXIdx(int val) {
    return val + MAX_VAL;
}

//toVY, toVX는 y,x 좌표계에서 ROW_MAX, COL_MAX의 RC 좌표계로 변환 (r1 -> 0, c1 ->0,)
// Virtual 좌표계라고 명함.
int toVYIdx(int val) {
    return toYIdx(val) - MAX_VAL - r1;
}

int toVXIdx(int val) {
    return toXIdx(val) - MAX_VAL - c1;
}


//RC 내부인지 파악, 탈출위해 사용
bool isRange(int y, int x) {
    int rIdx = toYIdx(y), cIdx = toXIdx(x);

    if (rIdx < 0 || rIdx >= MAX_IDX) return false;
    if (cIdx < 0 || cIdx >= MAX_IDX) return false;

    return true;
}

int arr[ROW_MAX][COL_MAX] = {{},};

//Virtual RC 내부인지 파악, 배열 저장 위해 사용
bool isVirtualRange(int y, int x) {
    int rIdx = toVYIdx(y), cIdx = toVXIdx(x);

    if (rIdx < 0 || rIdx > r2 - r1) return false;
    if (cIdx < 0 || cIdx > c2 - c1) return false;

    return true;

}

//자릿수 지정위해 최대 카운트 수를 저장
int maxCnt;

//배열 값 저장
void updateArr(int y, int x, int cnt) {
    if (isVirtualRange(y, x)) {
        arr[toVYIdx(y)][toVXIdx(x)] = cnt;
        maxCnt = cnt;
    }
}

void fillArr() {
    int y = 0, x = 0;
    int mult = 1, cnt = 1;

    updateArr(y, x, cnt);

    while (1) {
        //달팽이를 돈다.
        for (int i = 0; i < 4; ++i) {
            int yOff = offset[i][0];
            int xOff = offset[i][1];

            for (int j = 0; j < mult; ++j) {
                y += yOff;
                x += xOff;

                if (!isRange(y, x)) return;
                //arr 내부인 경우 카운트 증가
                ++cnt;
                //virtual arr에 갱신
                updateArr(y, x, cnt);
            }
            //달팽이 돌 때 사용
            if (i % 2 == 1) ++mult;
        }
    }
}

//자릿수 찾기 위해 사용, 정수 자릿수 구함.
int lenOf() {
    int ret = 0;
    int temp = maxCnt;

    while (temp > 0) {
        temp /= 10;
        ++ret;
    }

    return ret;
}

//배열을 출력
void printArr() {
    int cntLen = lenOf();
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            cout.width(cntLen + (j == c1 ? 0 : 1));
            cout << std::right << arr[i - r1][j - c1];
        }
        cout << '\n';
    }

}

// TC: O(r1^2)
// SC: O(r1^2)
void solve() {
    fillArr();
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