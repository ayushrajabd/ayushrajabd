class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i]++;
                j--;
            }
        }

        vector<int> ans;
        int i = 0, k = 0;
        bool changed = false;

        while (i < n && k < m) {
            if (word1[i] == word2[k]) {
                ans.push_back(i);
                k++;
                i++;
            } 
            else if (!changed && dp[i + 1] >= m - k - 1) {
                ans.push_back(i);
                k++;
                i++;
                changed = true;
            } 
            else {
                i++;
            }
        }

        if (k != m)
            return {};

        return ans;
    }
};