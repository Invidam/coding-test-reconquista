class UnionFind {
private:
    vector<int> parent;
public:
    int size;
    UnionFind(int size): size(size) {
        parent.resize(size + 1, -1);
    }
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;

        if(parent[a] > parent[b]) {
            int temp = a;
            a = b;
            b = temp;
        }

        parent[a] += parent[b];
        parent[b] = a;

        --size;
        return true;

    }

    int find(int node) {
        if(parent[node] < 0) return node;

        return parent[node] = find(parent[node]);
    }

    bool canMerge(int a, int b) {
        return find(a) != find(b);
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(), [&](auto const& a, auto const& b) {return a[0] > b[0];});

        UnionFind alice(n);
        UnionFind bob(n);

        int edgeSize = 0;
        for(const auto& edge: edges) {
            bool hasMerge = false;
            if(edge[0] == 1) {
                hasMerge |= alice.merge(edge[1], edge[2]);
            } else if(edge[0] == 2) {
                hasMerge |= bob.merge(edge[1], edge[2]);
            } else {
                hasMerge |= alice.merge(edge[1], edge[2]);
                hasMerge |= bob.merge(edge[1], edge[2]);
            }
            edgeSize += hasMerge;

            if(alice.size == 1 && bob.size == 1) break;
        }
        if(!(alice.size == 1 && bob.size == 1)) return -1;

        return edges.size() - edgeSize;
    }
};