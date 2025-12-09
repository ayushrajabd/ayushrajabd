class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;

        for (int x : nums) right[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            right[nums[j]]--;   
            long long target = nums[j] * 2LL;

            long long leftCount = left[target];
            long long rightCount = right[target];

            ans = (ans + (leftCount * rightCount) % MOD) % MOD;

            left[nums[j]]++;    
        }

        return ans % MOD;
    }
};