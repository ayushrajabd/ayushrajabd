class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;
        unordered_map<long long, long long> freq;
        
        for (auto &p : points) {
            freq[p[1]]++;
        }
        
        long long ans = 0;
        long long prefix = 0;
        
        for (auto &it : freq) {
            long long k = it.second;
            if (k >= 2) {
                long long c = (k * (k - 1) / 2) % MOD;
                ans = (ans + prefix * c) % MOD;
                prefix = (prefix + c) % MOD;
            }
        }
        
        return (int)ans;
    }
};
