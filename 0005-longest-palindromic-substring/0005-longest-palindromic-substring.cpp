

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxlength = 1;
        bool arr[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = false;
        for (int i = 0; i < n; i++)
            arr[i][i] = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                arr[i][i + 1] = true; 
                start = i;
                maxlength = 2;
            }
        }

        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && arr[i + 1][j - 1]) {
                    arr[i][j] = true;
                    if (len > maxlength) {
                        start = i;
                        maxlength = len;
                    }
                }
            }
        }

        return s.substr(start, maxlength);
    }
};


