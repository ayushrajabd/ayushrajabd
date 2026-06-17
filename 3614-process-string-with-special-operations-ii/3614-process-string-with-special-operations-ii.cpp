class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        long long curLen = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (curLen > 0) curLen--;
            }
            else if (s[i] == '#') {
                curLen *= 2;
            }
            else if (s[i] == '%') {
            }
            else {
                curLen++;
            }
            len[i] = curLen;
        }

        if (k >= curLen) return '.';

        for (int i = n - 1; i >= 0; i--) {
            long long prevLen = (i == 0 ? 0 : len[i - 1]);

            if (s[i] == '*') {
                continue;
            }
            else if (s[i] == '#') {
                if (prevLen == 0) continue;
                k %= prevLen;
            }
            else if (s[i] == '%') {
                k = prevLen - 1 - k;
            }
            else {
                if (k == prevLen) return s[i];
            }
        }

        return '.';
    }
};