class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        vector<int> pos(n);
        vector<int> comp(n);

        int cid = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && v[i].first - v[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
            pos[v[i].second] = i;
        }

       
        vector<int> nxt(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) j = i;
            while (j + 1 < n && v[j + 1].first - v[i].first <= maxDiff)
                j++;
            nxt[i] = j;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int vpos = pos[q[1]];

            if (u == vpos) {
                ans.push_back(0);
                continue;
            }

            if (u > vpos) swap(u, vpos);

            if (comp[u] != comp[vpos]) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < vpos) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};