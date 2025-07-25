class Solution {
public:
    bool isprime(int n) {
        if(n < 2) return false;
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    
    int createPalindrome(int x, bool oddLength) {
        int res = x;
        if (oddLength) x /= 10;
        while(x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }

    int primePalindrome(int n) {
        if(n <= 2) return 2;
        if(n <= 3) return 3;
        if(n <= 5) return 5;
        if(n <= 7) return 7;
        if(n <= 11) return 11;

        
        for(int len = 1; len < 100000; len++) {
            int p = createPalindrome(len, true); 
            if(p >= n && isprime(p)) {
                return p;
            }
        }

        return -1; 
    }
};
