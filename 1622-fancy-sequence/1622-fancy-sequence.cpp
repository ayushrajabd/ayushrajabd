class Fancy {
public:
    long long mod = 1000000007;
    vector<long long> arr;
    long long mul = 1, add = 0;

    long long modinv(long long x){
        long long p = mod - 2, res = 1;
        while(p){
            if(p & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long v = ((val - add) % mod + mod) % mod;
        v = (v * modinv(mul)) % mod;
        arr.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx] * mul % mod + add) % mod;
    }
};