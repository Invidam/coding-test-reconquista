#include <iostream>
#include <vector>
#include <queue>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
const int INF = 987654321;
const int OFFSET[2][2] = {{1, 0},
                    {0, 1}};
int TC, M, N;

int getShortestPath(const vector<vector<int>> &adj) {
    vector<vector<int>> distances(M, vector<int>(N, INF));

    queue<pair<int, int>> q;
    distances[0][0] = adj[0][0];
    q.emplace(0, 0);
    while (!q.empty()) {
        int currR = q.front().first;
        int currC = q.front().second;
        q.pop();

        int currDistance = distances[currR][currC];

        for (int i = 0; i < 2; ++i) {
            int nextR = currR + OFFSET[i][0];
            int nextC = currC + OFFSET[i][1];

            if(nextR < 0 || nextR >= adj.size() || nextC < 0 || nextC >= adj[0].size()) {
                continue;
            }

            int nextDistanceCand = currDistance + adj[nextR][nextC];
            int &nextDistance = distances[nextR][nextC];

            if(nextDistanceCand >= nextDistance ) {
                continue;
            }

            nextDistance = nextDistanceCand;
            q.emplace(nextR, nextC);


        }
    }

    return distances[adj.size()-1][adj[0].size()-1];
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> M >> N;
        vector<vector<int>> arr(M, vector<int>(N));
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                cin >> arr[r][c];
            }
        }

        cout << getShortestPath(arr) << '\n';
    }
}
