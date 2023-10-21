class UnionFind {
    vector<int> id;
    int cnt; 
public:
    UnionFind(int n) : id(n), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        --cnt;
        id[p] = q;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& E) {
        sort(begin(E), end(E), [](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        int ans = 0;
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            if (uf.connected(u, v)) continue;
            uf.connect(u, v);
            ans += e[2];
        }
        return uf.getCount() == 1 ? ans : -1;
    }
};
