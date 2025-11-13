class Solution {
public:
    int maxOperations(string s) {
       long long ans = 0;
        int zeroGroups = 0;
        int n = s.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                
                if (i == n - 1 || s[i + 1] == '1') 
                    zeroGroups++;
            } else { 
                ans += zeroGroups;
            }
        }
        return ans;
    }
};