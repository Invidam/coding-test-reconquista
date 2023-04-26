#include <iostream>
#include <queue>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
const int INF = 987654321;

int TC, N, E, S, K;


vector<int> dijkstra(int S, const vector<vector<int>> &adj) {
    vector<bool> visited(adj.size() + 1, false);
    priority_queue<pair<int, int>> pq;

    vector<int> distances(N, INF);

    pq.emplace(0, S);
    distances[S] = 0;

    while (!pq.empty()) {
        while(!pq.empty() && visited[pq.top().second]) {
            pq.pop();
        }
        if(pq.empty()) {
            break;
        }

        int curr = pq.top().second;
        int weight = distances[curr];
        pq.pop();
        visited[curr] = true;

        for (int next = 0; next < adj[curr].size(); ++next) {
            int nextWeight = weight + adj[curr][next];

            if (nextWeight < distances[next]) {
                pq.emplace(-nextWeight, next);
                distances[next] = nextWeight;
            }
        }
    }

    return distances;
}

void printShortestPath(int S, const vector<int> &targets, vector<vector<int>> &adj) {
    vector<int> distances = dijkstra(S, adj);

    for (const auto &target: targets) {
        int path = distances[target];
        if (path >= INF) {
            cout << "-1";
        } else {
            cout << path;
        }
        cout << ' ';
    }
    cout << '\n';
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> N >> E >> S >> K;
        vector<int> targets(K);
        for (int j = 0; j < K; ++j) {
            cin >> targets[j];
        }
        vector<vector<int>> adj = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));
        for (int j = 0; j < E; ++j) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a][b] = min(adj[a][b], d);
        }

        printShortestPath(S, targets, adj);
    }
}
