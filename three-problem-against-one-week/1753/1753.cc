#include <iostream>
#include <queue>
#include <vector>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
typedef pair<int, int> p;
const int INF = 987654321;

int TC, N, M,K, A, B, C;
vector<vector<p>> adj;

void solve() {
    priority_queue<p> pq;

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);

    pq.emplace(-0, K);
    dist[K] = 0;

    while(!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        if(visited[curr]) {
            continue;
        }

        visited[curr] = true;

        for(auto nextP: adj[curr]) {
            int next = nextP.first;
            int weight = dist[curr] + nextP.second;
            if(visited[next] || dist[next] < weight) continue;
            dist[next] = weight;
            pq.emplace(-dist[next], next);
        }
    }

    for(auto d : dist) {
        if(d == INF) cout << "INF";
        else cout << d;

        cout << '\n';
    }


}

int main() {

    FAST_IO;

    cin >> N >> M >> K;
    --K;
    adj = vector<vector<p>>(N);

    for(int i=0;i<M;++i) {
        cin >> A >> B >> C;
        --A;--B;
        adj[A].emplace_back(B, C);
    }
    solve();
}
