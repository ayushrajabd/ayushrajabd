class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] != (i % 2 ? '1' : '0')) c1++;
            if(s[i] != (i % 2 ? '0' : '1')) c2++;
        }
        
        return min(c1, c2);
    }
};