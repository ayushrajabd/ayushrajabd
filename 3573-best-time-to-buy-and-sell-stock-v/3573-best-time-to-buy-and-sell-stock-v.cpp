class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        long long INF = 1e18;
        vector<long long> flat(k + 1, -INF);
        vector<long long> high(k + 1, -INF);
        vector<long long> low(k + 1, -INF);
        
        
        flat[0] = 0;
        
        for (int p : prices) {
            vector<long long> next_flat = flat;
            vector<long long> next_high = high;
            vector<long long> next_low = low;
            
            for (int j = 1; j <= k; ++j) {
                
                next_high[j] = max(next_high[j], flat[j-1] - p);
                
                
                next_low[j] = max(next_low[j], flat[j-1] + p);

               
                next_flat[j] = max(next_flat[j], high[j] + p);
                
                
                next_flat[j] = max(next_flat[j], low[j] - p);
            }
            
           
            flat = next_flat;
            high = next_high;
            low = next_low;
        }
        
        
        long long ans = 0;
        for (long long val : flat) {
            ans = max(ans, val);
        }
        
        return ans;
    }
};