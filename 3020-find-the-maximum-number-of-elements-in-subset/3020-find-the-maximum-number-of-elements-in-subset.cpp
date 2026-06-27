class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, (c % 2) ? c : c - 1);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int len = 1;

            while (freq[cur] >= 2) {
                long long nxt = cur * cur;
                if (nxt > 1000000000LL) break;
                if (!freq.count(nxt)) break;

                len += 2;
                ans = max(ans, len);
                cur = nxt;
            }
        }

        return ans;
    }
};