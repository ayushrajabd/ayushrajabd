class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
         int n = nums.size();
        const int MOD = 1e9+7;

        vector<long long> dp(n+1), pref(n+1);
        dp[0] = pref[0] = 1;

        deque<int> mn, mx;
        int l = 1;

        for(int r = 1; r <= n; r++){
            int x = nums[r-1];

            while(!mn.empty() && mn.back() > x) mn.pop_back();
            mn.push_back(x);

            while(!mx.empty() && mx.back() < x) mx.pop_back();
            mx.push_back(x);

            while(!mn.empty() && !mx.empty() && mx.front() - mn.front() > k){
                if(mn.front() == nums[l-1]) mn.pop_front();
                if(mx.front() == nums[l-1]) mx.pop_front();
                l++;
            }

            dp[r] = (pref[r-1] - (l > 1 ? pref[l-2] : 0) + MOD) % MOD;
            pref[r] = (pref[r-1] + dp[r]) % MOD;
        }

        return dp[n];
    }
};