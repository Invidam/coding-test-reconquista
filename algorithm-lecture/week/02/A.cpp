#include <iostream>
#include <cstring>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

typedef pair<int, int> p;
vector<p> whileCoords;

const int offset[4][3][2] = {
        {{0, 0}, {1,  0},  {0,  1}},
        {{0, 0}, {1,  0},  {1,  1}},
        {{0, 0}, {1,  1},  {0,  1}},
        {{0, 0}, {1, -1}, {1, 0}}
};

vector<string> board;
int TC, H, W;
const char BLACK = '#', WHITE = '.', COVER = 'X';

bool isValid(int r, int c) {
    return (0 <= r && r < H) && (0 <= c && c < W);
}

bool canFill(int r, int c, int idx) {
    for (int i = 0; i < 3; ++i) {
        int nextR = r + offset[idx][i][0];
        int nextC = c + offset[idx][i][1];

        if (!isValid(nextR, nextC) || board[nextR][nextC] != WHITE) return false;
    }

    return true;
}

void coverFor(bool isCover, int r, int c, int idx) {
    for (int i = 0; i < 3; ++i) {
        int nextR = r + offset[idx][i][0];
        int nextC = c + offset[idx][i][1];

        board[nextR][nextC] = isCover ? COVER : WHITE;
    }
}

bool isCompleted() {

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == WHITE) return false;
        }
    }
    return true;
}

int getCoverCount(int idx = 0) {
    if (idx == 0 && whileCoords.size() % 3 != 0) return 0;
    if (isCompleted()) return 1;
    if (idx >= whileCoords.size()) return 0;

    int r = whileCoords[idx].first, c = whileCoords[idx].second;

    int ret = 0;
    bool canCover = false;

    for (int i = 0; i < 4; ++i) {
        if (!canFill(r, c, i)) {
            continue;
        }
        canCover = true;

        coverFor(true, r, c, i);
        ret += solve(idx + 1);

        coverFor(false, r, c, i);
    }

    if (!canCover && board[r][c] == COVER) return solve(idx + 1);

    return ret;
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> H >> W;

        board = vector<string>(H);
        for (int j = 0; j < H; ++j) {
            cin >> board[j];
        }

        whileCoords.clear();
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (board[j][k] == WHITE)
                    whileCoords.emplace_back(j, k);
            }
        }
        cout << solve() << '\n';
    }
}