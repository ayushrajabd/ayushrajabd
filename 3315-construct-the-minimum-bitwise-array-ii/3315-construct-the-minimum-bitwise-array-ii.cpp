class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        
        for (int x : nums) {
            if (x == 2) {
                ans.push_back(-1);
            } else {
                int bit = 0;
                
                while ((x >> bit) & 1) {
                    bit++;
                }
                
               
                ans.push_back(x - (1 << (bit - 1)));
            }
        }
        return ans;
    }
};