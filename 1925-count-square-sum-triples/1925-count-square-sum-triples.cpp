class Solution {
public:
    int countTriples(int n) {
         int cnt = 0;
    for (int a = 1; a <= n; ++a) {
        int a2 = a * a;
        for (int b = 1; b <= n; ++b) {
            int s = a2 + b * b;
            int c = (int)floor(sqrt((double)s));
            if (c * c == s && c <= n) cnt++;
        }
    }
    return cnt;
    }
};