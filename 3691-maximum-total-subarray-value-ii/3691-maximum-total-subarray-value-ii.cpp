#include <vector>

using namespace std;

class Solution {
    struct DequeNode {
        int val;
        int count;
    };

    struct Result {
        long long count;
        long long sum;
    };

    Result get_less(const vector<int>& nums, int V, vector<DequeNode>& dq_max, vector<DequeNode>& dq_min) {
        int n = nums.size();
        int head_max = 0, tail_max = 0;
        int head_min = 0, tail_min = 0;
        
        long long total_count = 0;
        long long total_sum = 0;
        long long sum_max = 0, sum_min = 0;
        int l = 0;
        
        for (int r = 0; r < n; ++r) {
            int val = nums[r];
            
            int count_max = 1;
            while (tail_max > head_max && dq_max[tail_max - 1].val <= val) {
                count_max += dq_max[tail_max - 1].count;
                sum_max -= 1LL * dq_max[tail_max - 1].val * dq_max[tail_max - 1].count;
                tail_max--;
            }
            dq_max[tail_max++] = {val, count_max};
            sum_max += 1LL * val * count_max;
            
            int count_min = 1;
            while (tail_min > head_min && dq_min[tail_min - 1].val >= val) {
                count_min += dq_min[tail_min - 1].count;
                sum_min -= 1LL * dq_min[tail_min - 1].val * dq_min[tail_min - 1].count;
                tail_min--;
            }
            dq_min[tail_min++] = {val, count_min};
            sum_min += 1LL * val * count_min;
            
            while (l <= r && (dq_max[head_max].val - dq_min[head_min].val) >= V) {
                sum_max -= dq_max[head_max].val;
                dq_max[head_max].count--;
                if (dq_max[head_max].count == 0) head_max++;
                
                sum_min -= dq_min[head_min].val;
                dq_min[head_min].count--;
                if (dq_min[head_min].count == 0) head_min++;
                
                l++;
            }
            
            total_count += (r - l + 1);
            total_sum += (sum_max - sum_min);
        }
        
        return {total_count, total_sum};
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<DequeNode> dq_max(n + 1);
        vector<DequeNode> dq_min(n + 1);
        
        long long N = 1LL * n * (n + 1) / 2;
        long long target_count = N - k;
        
        long long low = 0, high = 1e9 + 5;
        long long best_V = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (get_less(nums, mid, dq_max, dq_min).count <= target_count) {
                best_V = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        Result res = get_less(nums, best_V, dq_max, dq_min);
        long long C = N - res.count; 
        long long total_sum = get_less(nums, 2e9 + 7, dq_max, dq_min).sum; 
        
        return total_sum - res.sum - 1LL * (C - k) * best_V;
    }
};