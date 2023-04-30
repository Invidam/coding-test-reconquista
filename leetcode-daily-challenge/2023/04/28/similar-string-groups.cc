class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size + 1, -1);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(parent[a] < parent[b]) {
            parent[a] += parent[b];
            parent[b] = a;
        } else {
            parent[b] += parent[a];
            parent[a] = b;
        }

    }
    int find(int node) {

        if(parent[node] < 0) return node;

        return parent[node] = find(parent[node]);
    }
};

class Solution {
public:
    bool isSimilar(const string& a, const string& b) {
        int cnt = 0;
        for(int i=0;i<a.size();++i) {
            cnt += a[i] != b[i];
            if(cnt > 2) return false;
        }

        return cnt != 1;
    }

    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size() + 1);
        int cnt = strs.size();

        for(int i=0;i<strs.size();++i) {
            for(int j=i + 1;j<strs.size();++j) {
                if(!isSimilar(strs[i], strs[j])) continue;
                if(uf.find(i) == uf.find(j)) continue;

                --cnt;
                uf.merge(i, j);
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int cnt;
    void updateGroup(int idx, const vector<string>& arr, vector<bool>& visited) {
        if(idx >= arr.size()) return;
        visited[idx] = true;

        const string& str = arr[idx];
        for(int i=0;i<arr.size();++i) {
            if(visited[i]) continue;

            const string& next = arr[i];
            int diffCnt = 0;
            for(int j=0;j<str.size();++j) {
                if(next[j] == str[j]) continue;

                ++diffCnt;
                if(diffCnt > 2) break;
            }

            if(diffCnt == 0) visited[i] = true;
            if(diffCnt != 2 || visited[i]) continue;

            updateGroup(i, arr, visited);
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        cnt = 0;

        vector<bool> visited(strs.size() +1, false);
        for(int j=0;j<strs.size();++j) {
            if(visited[j]) continue;
            updateGroup(j, strs, visited);
            ++cnt;
        }

        return cnt;
    }
};