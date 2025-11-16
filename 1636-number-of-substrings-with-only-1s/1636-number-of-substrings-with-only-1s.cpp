class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long count = 0;
        long long current = 0;

        for (char c : s) {
            if (c == '1') {
                current++;
                count = (count + current) % MOD;
            } else {
                current = 0;
            }
        }
        return count;
    }
};