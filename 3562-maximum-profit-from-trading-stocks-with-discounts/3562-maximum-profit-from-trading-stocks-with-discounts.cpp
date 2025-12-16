class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : hierarchy) {
            adj[edge[0]].push_back(edge[1]);
        }

        function<pair<vector<int>, vector<int>>(int)> dfs = [&](int u) -> pair<vector<int>, vector<int>> {
            vector<int> chain_buy(budget + 1, -1e9);
            vector<int> chain_no_buy(budget + 1, -1e9);
            
            chain_buy[0] = 0;
            chain_no_buy[0] = 0;

            for (int v : adj[u]) {
                pair<vector<int>, vector<int>> child_res = dfs(v);
                vector<int>& c_bought = child_res.first;    
                vector<int>& c_no_buy = child_res.second;   

                vector<int> next_chain_buy(budget + 1, -1e9);
                for (int i = 0; i <= budget; ++i) {
                    if (chain_buy[i] == -1e9) continue;
                    for (int j = 0; j <= budget - i; ++j) {
                        if (c_bought[j] > -1e9) {
                            next_chain_buy[i + j] = max(next_chain_buy[i + j], chain_buy[i] + c_bought[j]);
                        }
                    }
                }
                chain_buy = next_chain_buy;

                vector<int> next_chain_no_buy(budget + 1, -1e9);
                for (int i = 0; i <= budget; ++i) {
                    if (chain_no_buy[i] == -1e9) continue;
                    for (int j = 0; j <= budget - i; ++j) {
                        if (c_no_buy[j] > -1e9) {
                            next_chain_no_buy[i + j] = max(next_chain_no_buy[i + j], chain_no_buy[i] + c_no_buy[j]);
                        }
                    }
                }
                chain_no_buy = next_chain_no_buy;
            }

            vector<int> res_parent_bought(budget + 1, -1e9);
            vector<int> res_parent_not_bought(budget + 1, -1e9);

            int p = present[u - 1];
            int f = future[u - 1];
            
            int cost_full = p;
            int profit_full = f - p;
            
            int cost_half = p / 2;
            int profit_half = f - cost_half;

            for (int i = 0; i <= budget; ++i) {
                if (chain_no_buy[i] > -1e9)
                    res_parent_not_bought[i] = max(res_parent_not_bought[i], chain_no_buy[i]);
            }
            if (cost_full <= budget) {
                for (int i = 0; i <= budget - cost_full; ++i) {
                    if (chain_buy[i] > -1e9) {
                        res_parent_not_bought[i + cost_full] = max(res_parent_not_bought[i + cost_full], chain_buy[i] + profit_full);
                    }
                }
            }

            for (int i = 0; i <= budget; ++i) {
                if (chain_no_buy[i] > -1e9)
                    res_parent_bought[i] = max(res_parent_bought[i], chain_no_buy[i]);
            }
            if (cost_half <= budget) {
                for (int i = 0; i <= budget - cost_half; ++i) {
                    if (chain_buy[i] > -1e9) {
                        res_parent_bought[i + cost_half] = max(res_parent_bought[i + cost_half], chain_buy[i] + profit_half);
                    }
                }
            }

            return {res_parent_bought, res_parent_not_bought};
        };

        pair<vector<int>, vector<int>> root_res = dfs(1);
        
        int ans = 0;
        for (int x : root_res.second) {
            ans = max(ans, x);
        }
        return ans;
    }
};