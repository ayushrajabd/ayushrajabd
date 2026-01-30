class Solution {
public:
    static constexpr long long INF = 1000000000000000000LL;

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        int n = source.size();

        unordered_map<int, unordered_map<string, unordered_map<string, long long>>> conv;

        for (int i = 0; i < original.size(); i++) {
            int len = original[i].size();
            auto &m = conv[len];
            if (!m[original[i]].count(changed[i]) ||
                m[original[i]][changed[i]] > cost[i]) {
                m[original[i]][changed[i]] = cost[i];
            }
        }

        for (auto &[len, mp] : conv) {
            vector<string> nodes;
            for (auto &p : mp) {
                nodes.push_back(p.first);
                for (auto &q : p.second)
                    nodes.push_back(q.first);
            }

            sort(nodes.begin(), nodes.end());
            nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

            for (auto &k : nodes)
                for (auto &i : nodes)
                    if (mp[i].count(k))
                        for (auto &j : nodes)
                            if (mp[k].count(j)) {
                                long long nd = mp[i][k] + mp[k][j];
                                if (!mp[i].count(j) || mp[i][j] > nd)
                                    mp[i][j] = nd;
                            }
        }

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                if (!conv.count(len)) continue;

                string s = source.substr(i, len);
                string t = target.substr(i, len);

                if (conv[len].count(s) && conv[len][s].count(t))
                    dp[i] = min(dp[i], conv[len][s][t] + dp[j + 1]);
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
