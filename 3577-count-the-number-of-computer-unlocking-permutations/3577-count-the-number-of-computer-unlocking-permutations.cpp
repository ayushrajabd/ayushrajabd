class Solution {
public:
    static const long long MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        long long ans = 1;
        int rootComplexity = complexity[0];

        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= rootComplexity) {
                return 0;
            }
            ans = (ans * i) % MOD;
        }

        return (int)ans;
    }
};