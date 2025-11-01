class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> ri;
        ri[0] = -1;
        long long ps = 0;

        for (int i = 0; i < nums.size(); i++) {
            ps += nums[i];

            int a = (k == 0) ? ps : ps % k;
            if (a < 0) a += k;

            if (ri.find(a) != ri.end()) {
                
                if (i - ri[a] >= 2)
                    return true;
            } else {
                ri[a] = i; 
            }
        }

        return false;
    }
};