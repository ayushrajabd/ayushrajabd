class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;
        if (m == 1) return 0;

        vector<long long> up(m), down(m);
        vector<long long> prefUp(m), prefDown(m);
        vector<long long> newUp(m), newDown(m);

      
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            prefUp[0] = up[0];
            prefDown[0] = down[0];

            for (int i = 1; i < m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            long long totalUp = prefUp[m - 1];

            for (int x = 0; x < m; x++) {
                newUp[x] = (x > 0 ? prefDown[x - 1] : 0);
                newDown[x] = (totalUp - prefUp[x] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        if (n == 2) {
            for (int i = 0; i < m; i++) {
                ans = (ans + up[i] + down[i]) % MOD;
            }
        } else {
            for (int i = 0; i < m; i++) {
                ans = (ans + up[i] + down[i]) % MOD;
            }
        }

        return ans;
    }
};