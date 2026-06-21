class Solution {
public:
    struct Node {
        long long sum;
        int idx;
        int lv, rv;

        bool operator>(const Node& other) const {
            if (sum != other.sum) return sum > other.sum;
            return idx > other.idx; 
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> val(nums.begin(), nums.end());
        vector<int> prev(n), next(n), ver(n, 0);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = (i + 1 < n ? i + 1 : -1);
        }

        auto isDescent = [&](int a, int b) -> int {
            if (a == -1 || b == -1) return 0;
            return val[a] > val[b];
        };

        int descents = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (val[i] > val[i + 1]) descents++;
        }

        if (descents == 0) return 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({val[i] + val[i + 1], i, ver[i], ver[i + 1]});
        }

        int operations = 0;

        while (descents > 0) {
            Node cur;

            while (true) {
                cur = pq.top();
                pq.pop();

                int i = cur.idx;
                int j = next[i];

                if (!alive[i] || j == -1 || !alive[j]) continue;
                if (ver[i] != cur.lv || ver[j] != cur.rv) continue;

                break;
            }

            int i = cur.idx;
            int j = next[i];
            int p = prev[i];
            int nj = next[j];

           
            descents -= isDescent(p, i);
            descents -= isDescent(i, j);
            descents -= isDescent(j, nj);

            
            val[i] += val[j];
            ver[i]++;
            alive[j] = false;

            next[i] = nj;
            if (nj != -1) prev[nj] = i;

            
            descents += isDescent(p, i);
            descents += isDescent(i, nj);

            
            if (p != -1) {
                pq.push({val[p] + val[i], p, ver[p], ver[i]});
            }
            if (nj != -1) {
                pq.push({val[i] + val[nj], i, ver[i], ver[nj]});
            }

            operations++;
        }

        return operations;
    }
};