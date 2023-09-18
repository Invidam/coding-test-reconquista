#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef pair<int, int> p;

const int OFFSET[4][2]= {{1,0}, {-1,0}, {0, 1}, {0, -1}};
int N, M;
vector<string> map;
int solve() {
    queue<p> q;
    bool visited[101][101];
    fill(&visited[0][0], &visited[N-1][M-1], false);

    q.emplace(0,0);
    visited[0][0] = true;

    int minLen = 1;
    while(!q.empty()) {
        int qSize = q.size();

        for(int j=0;j<qSize;++j) {
            p front = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                p next = p(front.first + OFFSET[i][0], front.second + OFFSET[i][1]);
                if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
                if (visited[next.first][next.second] || map[next.first][next.second] == '0') continue;

                if (next.first == N - 1 && next.second == M - 1) return minLen + 1;
                q.push(next);
                visited[next.first][next.second] = true;
            }
        }
        ++minLen;
    }

    return -1;
}

int main() {

    FAST_IO;

    cin >> N >> M;
    map.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    cout << solve();
}
