class Solution {
public:
long long calculateCombinations(const vector<int>& counts) {
    long long sum = 0;
    long long sqSum = 0;
    for (int x : counts) {
        sum += x;
        sqSum += (long long)x * x;
    }
    return (sum * sum - sqSum) / 2;
}

int getGcd(int a, int b) {
    return b == 0 ? a : getGcd(b, a % b);
}
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<int, int>, map<long long, int>> lines;
        map<pair<int, int>, map<pair<int, int>, int>> midpoints;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                
                int g = getGcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                long long intercept = (long long)dy * points[i][0] - (long long)dx * points[i][1];
                lines[{dy, dx}][intercept]++;

                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                midpoints[{mx, my}][{dy, dx}]++;
            }
        }

        long long totalTrapezoids = 0;
        
        for (auto& entry : lines) {
            vector<int> counts;
            for (auto& inner : entry.second) {
                counts.push_back(inner.second);
            }
            totalTrapezoids += calculateCombinations(counts);
        }

        long long duplicates = 0;

        for (auto& entry : midpoints) {
            vector<int> counts;
            for (auto& inner : entry.second) {
                counts.push_back(inner.second);
            }
            duplicates += calculateCombinations(counts);
        }

        return totalTrapezoids - duplicates;
    }
};