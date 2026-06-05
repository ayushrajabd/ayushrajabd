class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node memo[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos, bool tight, int len, int last2, int last1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][len][last2][last1]) {
            return memo[pos][len][last2][last1];
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (len == 0) {
                if (d == 0) {
                    Node child = dfs(pos + 1, ntight, 0, 10, 10);
                    totalCnt += child.cnt;
                    totalWav += child.wav;
                } else {
                    Node child = dfs(pos + 1, ntight, 1, 10, d);
                    totalCnt += child.cnt;
                    totalWav += child.wav;
                }
            }
            else if (len == 1) {
                Node child = dfs(pos + 1, ntight, 2, last1, d);

                totalCnt += child.cnt;
                totalWav += child.wav;
            }
            else {
                int add =
                    ((last2 < last1 && last1 > d) ||
                     (last2 > last1 && last1 < d));

                Node child = dfs(pos + 1, ntight, 2, last1, d);

                totalCnt += child.cnt;
                totalWav += child.wav + 1LL * add * child.cnt;
            }
        }

        Node ans = {totalCnt, totalWav};

        if (!tight) {
            vis[pos][len][last2][last1] = true;
            memo[pos][len][last2][last1] = ans;
        }

        return ans;
    }

    long long solve(long long N) {
        if (N < 0) return 0;

        s = to_string(N);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};