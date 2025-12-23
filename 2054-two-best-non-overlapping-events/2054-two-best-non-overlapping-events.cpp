class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int n = events.size();
        vector<int> suffixMax(n);
        
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }
        
        int maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i + 1;
            int right = n - 1;
            int nextEventIdx = -1;
            int targetEnd = events[i][1];
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > targetEnd) {
                    nextEventIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            int currentSum = events[i][2];
            if (nextEventIdx != -1) {
                currentSum += suffixMax[nextEventIdx];
            }
            
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};