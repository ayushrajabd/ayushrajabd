class Solution {
public:
    bool prime(int n){
        
        if(n<2)return false;
        if(n==2)return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
            
                return false;

            }
        }return true;
    }
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true); 
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }
};