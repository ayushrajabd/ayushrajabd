class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long total_periods = 0;
        long long current_streak = 0;

        for (int i = 0; i < prices.size(); ++i) {
            
            if (i > 0 && prices[i] == prices[i - 1] - 1) {
                current_streak++;
            } else {
                
                current_streak = 1;
            }
            
            
            total_periods += current_streak;
        }

        return total_periods;
    }
};