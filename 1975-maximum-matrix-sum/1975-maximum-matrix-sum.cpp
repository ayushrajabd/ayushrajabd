class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        long long minAbs = LLONG_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                long long ax = llabs((long long)x);
                sum += ax;
                minAbs = min(minAbs, ax);
            }
        }

        if (negCount % 2 == 0)
            return sum;
        else
            return sum - 2 * minAbs;
    }
};
