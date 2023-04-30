class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size + 1 , -1);
    }
    bool merged(int a, int b) {
        return find(a) == find(b);
    }
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;

        if(parent[a] < parent[b]) {
            parent[a] += parent[b];
            parent[b] = a;
        } else {
            parent[b] += parent[a];
            parent[a] = b;
        }

        return true;
    }

    int find(int node) {
        if(parent[node] < 0) return node;

        return parent[node] = find(parent[node]);
    }

};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();++i) {
            queries[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [&](auto const& a, auto const& b) {
            return a[2] < b[2];
        });

        sort(queries.begin(), queries.end(), [&](auto const& a, auto const& b) {
            return a[2] < b[2];
        });

        UnionFind uf(n + 1);

        int i = 0;

        vector<bool> ret(queries.size(),false);
        for(const auto& query: queries) {
            while(i < edges.size()) {
                if(query[2] <= edges[i][2]) break;

                uf.merge(edges[i][0], edges[i][1]);
                ++i;
            }

            if(uf.merged(query[0], query[1]))
                ret[query[3]] = true;
        }

        return ret;
    }
};