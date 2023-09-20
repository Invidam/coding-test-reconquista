#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> t;
struct Node{
    int weight;
    int curr;
    int parent;

    Node(int weight, int curr, int parent) : weight(weight), curr(curr), parent(parent) {}
};
int N, M, a, b, c;
vector<vector<p>> adj;
const int INF = 987654321;

void solve() {
    vector<int> parents(N, -1);
    vector<int> dist(N, INF);
    auto cmp = [](const  auto& n1, const auto& n2) {
        return n1.weight > n2.weight;
    };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    int s = 0;
    int cnt = 0;
    dist[s] = 0;
    pq.emplace(0, s, s);

    while(!pq.empty()) {
        int curr = pq.top().curr;
        int parent = pq.top().parent;
        pq.pop();

        if(parents[curr] != -1) continue;
        parents[curr] = parent;
        ++cnt;
//        if(curr != parent)
//            cout << parent + 1 << ' ' << curr + 1 << '\n';

        for(auto nextP: adj[curr]) {
            int next = nextP.first;
            int path = dist[curr] + nextP.second;

            if(parents[next] != -1 || dist[next] < path) continue;
            dist[next] =  path;
            pq.emplace(path, next, curr);
        }

    }
    cout << cnt - 1 << '\n';
    for(int curr=0;curr<N;++curr) {
        int parent = parents[curr];
        if(curr == parent) continue;

        cout << curr +1 << ' ' << parent + 1 << '\n';
    }
}

int main() {
    cin >> N >> M;

    adj.resize(N+1);
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;
        --a;--b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    solve();
}
