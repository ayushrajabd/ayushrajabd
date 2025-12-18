class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long currentProfit = 0;
        for (int i = 0; i < n; ++i) {
            currentProfit += (long long)prices[i] * strategy[i];
        }

        long long currentGain = 0;
        int halfK = k / 2;

        for (int i = 0; i < halfK; ++i) {
            currentGain -= (long long)prices[i] * strategy[i];
        }
        for (int i = halfK; i < k; ++i) {
            currentGain += (long long)prices[i] - (long long)prices[i] * strategy[i];
        }

        long long maxGain = std::max(0LL, currentGain);

        for (int i = 0; i < n - k; ++i) {
            int leaving = i;
            int mid = i + halfK;
            int entering = i + k;

            currentGain += (long long)prices[leaving] * strategy[leaving];
            currentGain -= (long long)prices[mid];
            currentGain += (long long)prices[entering] - (long long)prices[entering] * strategy[entering];

            maxGain = std::max(maxGain, currentGain);
        }

        return currentProfit + maxGain;
    }
};