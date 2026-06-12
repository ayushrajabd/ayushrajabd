class Solution {
public:
    static const int MOD = 1000000007;
    static const int LOG = 17;

    vector<int> depth;
    vector<vector<int>> up;
    vector<long long> pow2;

    void dfs(int u, int p, vector<vector<int>>& adj) {
        up[u][0] = p;

        for (int i = 1; i < LOG; i++) {
            if (up[u][i - 1] == -1)
                up[u][i] = -1;
            else
                up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i))
                u = up[u][i];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        dfs(1, -1, adj);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int w = lca(u, v);

            int len = depth[u] + depth[v] - 2 * depth[w];

            if (len == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)pow2[len - 1]);
            }
        }

        return ans;
    }
};